/*
* TiledMapLoader.cpp
*
*  Created on: 14 juil. 2013
*      Author: picque_j
*/

#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string.h>
#define MINIZ_NO_ZLIB_COMPATIBLE_NAMES
#define MINIZ_HEADER_FILE_ONLY
#include "utils/miniz.c"
#include "utils/Base64.hpp"
#include "TiledMapLoader.h"
#include "Helper.hpp"
namespace Tiled
{

	TiledMapLoader::TiledMapLoader()
	{

	}

	TiledMapLoader::~TiledMapLoader()
	{
		for (std::vector<Map *>::iterator it = _maps.begin(); it != _maps.end(); ++it)
			delete *it;
	}

	void TiledMapLoader::loadFromFile(const std::string &file)
	{
		std::ifstream in(file.c_str());

		if (in.fail())
			throw std::logic_error("File not found : " + file);

		_tiled.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
		_tiled.push_back('\0');

		if (_tiled.empty())
			throw std::logic_error("File is empty : " + file);

		parseDocument();
	}

	void TiledMapLoader::loadFromText(const std::string &text)
	{
		_tiled = text;

		if (_tiled.empty())
			throw std::logic_error("Text is empty");

		parseDocument();
	}

	void TiledMapLoader::parseDocument()
	{
		try
		{
			_document.parse<rapidxml::parse_no_data_nodes>(&_tiled[0]);
		}
		catch (rapidxml::parse_error &error)
		{
			std::string errorMessage("Parse error : ");

			errorMessage.append(error.what());
			throw std::logic_error(errorMessage);
		}
	}

	Map *TiledMapLoader::parseMap()
	{
		Map *map = new Map();
		rapidxml::xml_node<> *mapNode = 0;

		mapNode = _document.first_node("map");
		if (!mapNode)
			throw std::logic_error("Invalid tiled map : no map");
		map->setVersion(getStringProperty(mapNode, "version"));
		map->setOrientation(getStringProperty(mapNode, "orientation"));
		map->setTileWidth(getIntProperty(mapNode, "tilewidth"));
		map->setTileHeight(getIntProperty(mapNode, "tileheight"));
		map->setWidth(getIntProperty(mapNode, "width"));
		map->setHeight(getIntProperty(mapNode, "height"));
		loadTiledProperties(map, mapNode);
		parseTilesets(map, mapNode);
		parseLayers(map, mapNode);
		parseObjectGroup(map, mapNode);
		_maps.push_back(map);
		return map;
	}

	void TiledMapLoader::parseTilesets(Map *map, rapidxml::xml_node<> *mapNode)
	{
		Tileset *tileset = 0;
		int tilesetId = 0;
		rapidxml::xml_node<> *tilesetNode = 0;
		rapidxml::xml_node<> *tilesetImageNode = 0;
		rapidxml::xml_node<> *tilesetOffsetNode = 0;

		tilesetNode = mapNode->first_node("tileset");
		if (!tilesetNode)
			throw std::logic_error("Invalid tiled map : no tilesets");
		while (tilesetNode)
		{
			tileset = new Tileset();
			tilesetImageNode = tilesetNode->first_node("image");
			tilesetOffsetNode = tilesetNode->first_node("tileoffset");
			if (!tilesetImageNode)
				throw std::logic_error("Invalid tiled map : no tileset image");
			if (tilesetOffsetNode)
			{
				tileset->setOffsetX(getIntProperty(tilesetOffsetNode, "x"));
				tileset->setOffsetY(getIntProperty(tilesetOffsetNode, "y"));
			}
			tileset->setId(tilesetId);
			tileset->setFirstGid(getIntProperty(tilesetNode, "firstgid"));
			tileset->setName(getStringProperty(tilesetNode, "name"));
			tileset->setTileWidth(getIntProperty(tilesetNode, "tilewidth"));
			tileset->setTileHeight(getIntProperty(tilesetNode, "tileheight"));
			tileset->setImageSource(getStringProperty(tilesetImageNode, "source"));
			tileset->setWidth(getIntProperty(tilesetImageNode, "width"));
			tileset->setHeight(getIntProperty(tilesetImageNode, "height"));
			loadTiledProperties(tileset, tilesetNode);
			parseTilesetsTileProperties(map, tileset, tilesetNode);
			map->addTileset(tileset);
			tilesetNode = tilesetNode->next_sibling("tileset");
			++tilesetId;
		}
	}

	void TiledMapLoader::parseTilesetsTileProperties(Map *map, Tileset *tileset, rapidxml::xml_node<> *tilesetNode)
	{
		rapidxml::xml_node<> *tilesetTileNode = 0;
		rapidxml::xml_node<> *tilesetTileNodeProperties = 0;
		rapidxml::xml_node<> *tilesetTileNodeProperty = 0;

		tilesetTileNode = tilesetNode->first_node("tile");
		while (tilesetTileNode)
		{
			tilesetTileNodeProperties = tilesetTileNode->first_node("properties");
			if (tilesetTileNodeProperties)
			{
				tilesetTileNodeProperty = tilesetTileNodeProperties->first_node("property");
				while (tilesetTileNodeProperty)
				{
					char *name = getStringProperty(tilesetTileNodeProperty, "name");
					char *value = getStringProperty(tilesetTileNodeProperty, "value");

					if (name && value)
						tileset->addTileProperties(getIntProperty(tilesetTileNode, "id"), name, value);
					tilesetTileNodeProperty = tilesetTileNodeProperty->next_sibling("property");
				}
			}
			tilesetTileNode = tilesetTileNode->next_sibling("tile");
		}
	}

	void TiledMapLoader::parseLayers(Map *map, rapidxml::xml_node<> *mapNode)
	{
		Layer *layer = 0;
		rapidxml::xml_node<> *layerNode = 0;
		rapidxml::xml_node<> *layerDataNode = 0;

		layerNode = mapNode->first_node("layer");
		if (!layerNode)
			throw std::logic_error("Invalid tiled map : no layers");
		while (layerNode)
		{
			layer = new Layer();
			layerDataNode = layerNode->first_node("data");
			if (!layerDataNode)
				throw std::logic_error("Invalid tiled map : no layer data");
			layer->setName(getStringProperty(layerNode, "name"));
			layer->setWidth(getIntProperty(layerNode, "width"));
			layer->setHeight(getIntProperty(layerNode, "height"));
			layer->setVisible(getIntProperty(layerNode, "visible", 1));
			layer->setOpacity(getFloatProperty(layerNode, "opacity", 1));
			loadTiledProperties(layer, layerNode);
			parseTiles(map, layer, layerDataNode);
			map->addLayer(layer);
			layerNode = layerNode->next_sibling("layer");
		}
	}

	void TiledMapLoader::parseTiles(Map *map, Layer *layer, rapidxml::xml_node<> *layerDataNode)
	{
		rapidxml::xml_node<> *tileNode = 0;
		unsigned mapIterator = 0;
		unsigned gid = 0;

		if (!strncmp(getStringProperty(layerDataNode, "encoding"), "base64", 6) && !strncmp(getStringProperty(layerDataNode, "compression"), "zlib", 4))
		{
			std::string base64Tiles = Base64::decode(trim(layerDataNode->value()));
			unsigned numberOfGids = layer->getWidth() * layer->getHeight();
			unsigned tileIndex = 0;
			mz_ulong uncompressSize = numberOfGids << 2;
			unsigned char *gids = new unsigned char[uncompressSize];

			if (!gids)
				throw std::logic_error("Uncompression failed : can't allocate memory");

			if (mz_uncompress(gids, &uncompressSize, (unsigned char *) base64Tiles.c_str(), base64Tiles.length()) != MZ_OK)
				throw std::logic_error("Zlib error : uncompression failed");

			while (mapIterator < numberOfGids)
			{
				gid = gids[tileIndex] | gids[tileIndex + 1] << 8 | gids[tileIndex + 2] << 16 | gids[tileIndex + 3] << 24;
				if (gid)
					createTileFromGid(map, layer, gid, mapIterator);
				tileIndex += 4;
				++mapIterator;
			}
			delete[] gids;
		}
		else
		{
			tileNode = layerDataNode->first_node("tile");
			if (!tileNode)
				throw std::logic_error("Invalid tiled map : no tiles (only plain XML or ZLIB supported)");
			while (tileNode)
			{
				gid = getIntProperty(tileNode, "gid");
				if (gid)
					createTileFromGid(map, layer, gid, mapIterator);
				tileNode = tileNode->next_sibling("tile");
				++mapIterator;
			}
		}
	}

	void TiledMapLoader::parseObjectGroup(Map *map, rapidxml::xml_node<> *mapNode)
	{
		ObjectGroup *objectGroup = 0;
		rapidxml::xml_node<> *objectGroupNode = 0;

		objectGroupNode = mapNode->first_node("objectgroup");
		while (objectGroupNode)
		{
			objectGroup = new ObjectGroup();
			objectGroup->setName(getStringProperty(objectGroupNode, "name"));
			objectGroup->setDrawOrder(getStringProperty(objectGroupNode, "draworder"));
			objectGroup->setWidth(getIntProperty(objectGroupNode, "width"));
			objectGroup->setHeight(getIntProperty(objectGroupNode, "height"));
			objectGroup->setVisible(getIntProperty(objectGroupNode, "visible", 1));
			objectGroup->setOpacity(getFloatProperty(objectGroupNode, "opacity", 1));
			loadTiledProperties(objectGroup, objectGroupNode);
			parseObject(map, objectGroup, objectGroupNode);
			map->addObjectGroup(objectGroup);
			objectGroupNode = objectGroupNode->next_sibling("objectgroup");
		}
	}
	void TiledMapLoader::parseObject(Map *map, ObjectGroup *objectGroup, rapidxml::xml_node<> *objectGroupNode)
	{
		Object *object = 0;
		rapidxml::xml_node<> *objectNode = 0;
		rapidxml::xml_node<> *objectNature = 0;

		objectNode = objectGroupNode->first_node("object");
		while (objectNode)
		{
			object = new Object();
			object->setGid(getIntProperty(objectNode, "gid", -1));
			object->setName(getStringProperty(objectNode, "name"));
			object->setType(getStringProperty(objectNode, "type"));
			object->setX(getIntProperty(objectNode, "x"));
			object->setY(getIntProperty(objectNode, "y"));
			object->setWidth(getIntProperty(objectNode, "width"));
			object->setHeight(getIntProperty(objectNode, "height"));
			object->setRotation(getFloatProperty(objectNode, "rotation"));
			object->setVisible(getIntProperty(objectNode, "visible", 1));
			objectNature = objectNode->first_node("ellipse");
			if (objectNature)
				object->setPolygonType("ellipse");
			objectNature = objectNode->first_node("polygon");
			if (objectNature)
			{
				object->setPolygonType("polygon");
				object->setVertices(getStringProperty(objectNature, "points"));
			}
			objectNature = objectNode->first_node("polyline");
			if (objectNature)
			{
				object->setPolygonType("polyline");
				object->setVertices(getStringProperty(objectNature, "points"));
			}
			loadTiledProperties(object, objectNode);
			objectGroup->addObject(object);
			objectNode = objectNode->next_sibling("object");
		}
	}
}

