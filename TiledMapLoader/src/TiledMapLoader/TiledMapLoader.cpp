#ifdef _WIN32
#include <direct.h>
#define chdir _chdir
#define getcwd _getcwd
#else
	#include <unistd.h>
#endif

#include <cstring>
#include <stdexcept>
#include <fstream>

#define MINIZ_NO_ZLIB_COMPATIBLE_NAMES
#define MINIZ_HEADER_FILE_ONLY
#include "../lib/miniz/miniz.c"
#include "../lib/rapidxml/rapidxml.hpp"

#include <TiledMapLoader/TiledMapLoader.h>
#include <TiledMapLoader/StringUtils.h>
#include <TiledMapLoader/Base64.hpp>
#include <TiledMapLoader/XMLElement.h>

namespace TiledMapLoader {
	Map::Ptr TiledMapLoader::loadMap(const std::string &mapFile, const std::string &mapPath) {
		Map::Ptr mapPtr(new Map);
		changeCurrentDirectory(mapPath);
		std::ifstream in(mapFile);
		std::string fileContentString;
		if (in.fail()) {
			throw std::logic_error("File not found: " + mapPath + "/" + mapFile);
		}
		fileContentString.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
		fileContentString.push_back(0);
		loadInternalMap(*mapPtr.get(), &fileContentString[0]);
		restoreCurrentDirectory();
		return std::move(mapPtr);
	}

	inline void TiledMapLoader::changeCurrentDirectory(const std::string &mapPath) {
		getcwd(mCwd, 1024);
		chdir(mapPath.c_str());
	}

	void TiledMapLoader::restoreCurrentDirectory() {
		chdir(mCwd);
	}

	void TiledMapLoader::loadInternalMap(Map &map, char *xml) {
		rapidxml::xml_document<> document;
		rapidxml::xml_node<> *rootNode = nullptr;
		document.parse<rapidxml::parse_no_data_nodes>(xml);
		rootNode = document.first_node("map");
		if (!rootNode) {
			throw std::logic_error("Invalid tiled map: no map tag");
		}
		auto &rootNodeRef = *rootNode;
		XMLElement mapElement(*rootNode);
		map.setVersion(mapElement.getString("version"));
		map.setWidth(mapElement.getInt("width"));
		map.setHeight(mapElement.getInt("height"));
		map.setTileWidth(mapElement.getInt("tilewidth"));
		map.setTileHeight(mapElement.getInt("tileheight"));
		map.parseProperties(*rootNode);

		loadTilesets(map, rootNodeRef);
		loadLayers(map, rootNodeRef);
		loadObjectGroups(map, rootNodeRef);
	}

	void TiledMapLoader::loadTilesets(Map &map, rapidxml::xml_node<> &rootNode) {
		auto tilesetNode = rootNode.first_node("tileset");
		char *tilesetSource = nullptr;
		auto tilesetId = 0;
		if (!tilesetNode) {
			throw std::logic_error("Invalid tiled map: no tileset tag");
		}
		while (tilesetNode) {
			XMLElement tilesetElement(*tilesetNode);
			tilesetSource = tilesetElement.getString("source", nullptr);

			if (tilesetSource) {
				loadExternalTileset(map, tilesetId, tilesetSource, tilesetElement.getInt("firstgid"));
			} else {
				addTileset(map, tilesetId, *tilesetNode);
			}
			tilesetNode = tilesetNode->next_sibling("tileset");
			++tilesetId;
		}
	}

	void TiledMapLoader::loadExternalTileset(Map &map, int tilesetId, const std::string &tilesetFile, unsigned firstGid) {
		rapidxml::xml_document<> document;
		rapidxml::xml_node<> *tilesetNode = nullptr;
		std::ifstream in(tilesetFile);
		std::string fileContentString;
		if (in.fail()) {
			throw std::logic_error("File not found (external tileset) : " + tilesetFile);
		}
		fileContentString.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
		fileContentString.push_back(0);
		document.parse<rapidxml::parse_no_data_nodes>(&fileContentString[0]);
		tilesetNode = document.first_node("tileset");
		if (!tilesetNode) {
			throw std::logic_error("Invalid tiled map: no tileset tag (external tileset " + tilesetFile + ")");
		}
		addTileset(map, tilesetId, *tilesetNode, firstGid);
	}

	void TiledMapLoader::addTileset(Map &map, int tilesetId, rapidxml::xml_node<> &tilesetNode, unsigned firstGid) {
		Tileset::Ptr tileset(new Tileset);
		rapidxml::xml_node<> *tilesetImageNode = nullptr;
		rapidxml::xml_node<> *tilesetOffsetNode = nullptr;
		tilesetImageNode = tilesetNode.first_node("image");
		if (!tilesetImageNode) {
			throw std::logic_error("Invalid tiled map: no tileset image tag");
		}
		XMLElement tilesetElement(tilesetNode);
		XMLElement tilesetImageElement(*tilesetImageNode);
		tilesetOffsetNode = tilesetNode.first_node("tileoffset");
		if (tilesetOffsetNode) {
			XMLElement element(*tilesetOffsetNode);
			tileset->setOffsetX(element.getInt("x"));
			tileset->setOffsetY(element.getInt("y"));
		} else {
			tileset->setOffsetX(0);
			tileset->setOffsetY(0);
		}
		tileset->setId(tilesetId);
		if (firstGid) {
			tileset->setFirstGid(firstGid);
		} else {
			tileset->setFirstGid(tilesetElement.getInt("firstgid"));
		}
		tileset->setName(tilesetElement.getString("name"));
		tileset->setTileWidth(tilesetElement.getInt("tilewidth"));
		tileset->setTileHeight(tilesetElement.getInt("tileheight"));
		tileset->setSpacing(tilesetElement.getInt("spacing"));
		tileset->setMargin(tilesetElement.getInt("margin"));
		tileset->setImageSource(tilesetImageElement.getString("source"));
		tileset->setWidth(tilesetImageElement.getInt("width"));
		tileset->setHeight(tilesetImageElement.getInt("height"));
		tileset->parseProperties(tilesetNode);
		parseTilesetsTileProperties(map, *(tileset.get()), tilesetNode);
		map.addTileset(std::move(tileset));
	}

	void TiledMapLoader::parseTilesetsTileProperties(Map &map, Tileset &tileset, rapidxml::xml_node<> &tilesetNode) {
		rapidxml::xml_node<> *tilesetTileNode = nullptr;
		rapidxml::xml_node<> *tilesetTileNodeProperties = nullptr;
		rapidxml::xml_node<> *tilesetTileNodeProperty = nullptr;

		tilesetTileNode = tilesetNode.first_node("tile");
		while (tilesetTileNode) {
			tilesetTileNodeProperties = tilesetTileNode->first_node("properties");
			if (tilesetTileNodeProperties) {
				tilesetTileNodeProperty = tilesetTileNodeProperties->first_node("property");
				while (tilesetTileNodeProperty) {
					XMLElement tileNode(*tilesetTileNode);
					XMLElement tileNodeProperty(*tilesetTileNodeProperty);
					char *name = tileNodeProperty.getString("name");
					char *value = tileNodeProperty.getString("value");
					if (name && value) {
						tileset.addTileProperties(tileNode.getInt("id"), name, value);
					}
					tilesetTileNodeProperty = tilesetTileNodeProperty->next_sibling("property");
				}
			}
			tilesetTileNode = tilesetTileNode->next_sibling("tile");
		}
	}

	void TiledMapLoader::loadLayers(Map &map, rapidxml::xml_node<> &rootNode) {
		rapidxml::xml_node<> *layerNode = nullptr;
		rapidxml::xml_node<> *layerDataNode = nullptr;
		int layerId = 0;
		layerNode = rootNode.first_node("layer");
		if (!layerNode) {
			throw std::logic_error("Invalid tiled map: no layer tag");
		}
		while (layerNode) {
			Layer::Ptr layer(new Layer);
			layerDataNode = layerNode->first_node("data");
			if (!layerDataNode) {
				throw std::logic_error("Invalid tiled map : no layer data tag");
			}
			XMLElement layerElement(*layerNode);
			layer->setId(layerId);
			layer->setName(layerElement.getString("name"));
			layer->setWidth(layerElement.getInt("width"));
			layer->setHeight(layerElement.getInt("height"));
			layer->setVisible(layerElement.getInt("visible", 1));
			layer->setOpacity(layerElement.getFloat("opacity", 1));
			layer->parseProperties(*layerNode);
			loadLayerTiles(map, *layer.get(), *layerDataNode);
			map.addLayer(std::move(layer));
			layerNode = layerNode->next_sibling("layer");
			++layerId;
		}
	}

	void TiledMapLoader::loadLayerTiles(Map &map, Layer &layer, rapidxml::xml_node<> &layerDataNode) {
		rapidxml::xml_node<> *tileNode = nullptr;
		XMLElement layerDataElement(layerDataNode);
		unsigned mapIterator = 0;
		unsigned gid = 0;
		if (!strncmp(layerDataElement.getString("encoding"), "base64", 6) && !strncmp(layerDataElement.getString("compression"), "zlib", 4)) {
			auto base64Tiles = Base64::decode(trim(layerDataElement.getValue()));
			unsigned numberOfGids = layer.getWidth()  *layer.getHeight();
			unsigned tileIndex = 0;
			mz_ulong uncompressSize = numberOfGids << 2;
			auto gids = new unsigned char[uncompressSize];
			if (!gids) {
				throw std::logic_error("Uncompression failed: can't allocate memory");
			}
			if (mz_uncompress(gids, &uncompressSize, (unsigned char *) base64Tiles.c_str(), base64Tiles.length()) != MZ_OK) {
				throw std::logic_error("Zlib error: uncompression failed");
			}
			while (mapIterator < numberOfGids) {
				gid = gids[tileIndex] | gids[tileIndex + 1] << 8 | gids[tileIndex + 2] << 16 | gids[tileIndex + 3] << 24;
				if (gid)
					createTileFromGid(map, layer, gid, mapIterator);
				tileIndex += 4;
				++mapIterator;
			}
			delete[] gids;
		}
		else {
			tileNode = layerDataNode.first_node("tile");
			if (!tileNode) {
				throw std::logic_error("Invalid tiled map: no tiles (only plain XML or ZLIB supported)");
			}
			while (tileNode) {
				XMLElement tileElement(*tileNode);
				gid = tileElement.getUnsignedInt("gid");
				if (gid) {
					createTileFromGid(map, layer, gid, mapIterator);
				}
				tileNode = tileNode->next_sibling("tile");
				++mapIterator;
			}
		}
	}

	void TiledMapLoader::createTileFromGid(Map &map, Layer &layer, unsigned gid, unsigned mapIterator) {
		Tile::Ptr tile(new Tile);
		auto &tileRef = *tile.get();
		tile->setGid(gid);
		const auto &tileset = map.getTilesetFromGid(tile->getGid());
		tile->setWidth(tileset.getTileWidth());
		tile->setHeight(tileset.getTileHeight());
		tile->setX((mapIterator % layer.getWidth())  *tileset.getTileWidth() + tileset.getOffsetX());
		tile->setY((mapIterator / layer.getWidth())  *tileset.getTileHeight() + tileset.getOffsetY());
		tile->setTilesetId(tileset.getId());
		tile->setTilesetX(tileset.getTilePositionOnTilesetX(tileRef));
		tile->setTilesetY(tileset.getTilePositionOnTilesetY(tileRef));
		layer.addTile(std::move(tile));
	}

	void TiledMapLoader::loadObjectGroups(Map &map, rapidxml::xml_node<> &rootNode) {
		rapidxml::xml_node<> *objectGroupNode = nullptr;
		objectGroupNode = rootNode.first_node("objectgroup");
		while (objectGroupNode) {
			ObjectGroup::Ptr objectGroup(new ObjectGroup);
			XMLElement objectGroupElement(*objectGroupNode);
			objectGroup->setName(objectGroupElement.getString("name"));
			objectGroup->setDrawOrder(objectGroupElement.getString("draworder"));
			objectGroup->setWidth(objectGroupElement.getInt("width"));
			objectGroup->setHeight(objectGroupElement.getInt("height"));
			objectGroup->setVisible(objectGroupElement.getInt("visible", 1));
			objectGroup->setOpacity(objectGroupElement.getFloat("opacity", 1));
			objectGroup->parseProperties(*objectGroupNode);
			loadObjectGroupObjects(map, *objectGroup.get(), *objectGroupNode);
			map.addObjectGroup(std::move(objectGroup));
			objectGroupNode = objectGroupNode->next_sibling("objectgroup");
		}
	}

	void TiledMapLoader::loadObjectGroupObjects(Map &map, ObjectGroup &objectGroup, rapidxml::xml_node<> &objectGroupNode) {
		rapidxml::xml_node<> *objectNode = nullptr;
		rapidxml::xml_node<> *objectNature = nullptr;
		objectNode = objectGroupNode.first_node("object");
		while (objectNode) {
			Object::Ptr object(new Object);
			XMLElement objectGroupElement(*objectNode);
			object->setGid(objectGroupElement.getInt("gid", -1));
			object->setId(objectGroupElement.getInt("id", -1));
			object->setName(objectGroupElement.getString("name"));
			object->setType(objectGroupElement.getString("type"));
			object->setX(objectGroupElement.getFloat("x"));
			object->setY(objectGroupElement.getFloat("y"));
			object->setWidth(objectGroupElement.getFloat("width"));
			object->setHeight(objectGroupElement.getFloat("height"));
			object->setRotation(objectGroupElement.getFloat("rotation"));
			object->setVisible(objectGroupElement.getInt("visible", 1));
			objectNature = objectNode->first_node("ellipse");
			if (objectNature) {
				object->setPolygonType("ellipse");
			}
			objectNature = objectNode->first_node("polygon");
			if (objectNature) {
				XMLElement objectNatureElement(*objectNature);

				object->setPolygonType("polygon");
				object->setVertices(objectNatureElement.getString("points"));
			}
			objectNature = objectNode->first_node("polyline");
			if (objectNature) {
				XMLElement objectNatureElement(*objectNature);

				object->setPolygonType("polyline");
				object->setVertices(objectNatureElement.getString("points"));
			}
			object->parseProperties(*objectNode);
			objectGroup.addObject(std::move(object));
			objectNode = objectNode->next_sibling("object");
		}
	}
}
