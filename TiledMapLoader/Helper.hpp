/*
 * Helper.hpp
 *
 *  Created on: 14 juil. 2013
 *      Author: picque_j
 */

#ifndef HELPER_HPP_
#define HELPER_HPP_

#include <vector>
#include "map/IProperty.hpp"
#include "map/Tileset.h"
#include "rapidxml/rapidxml.hpp"

namespace Tiled
{

    const std::string WHITESPACE = " \n\r\t";

    static std::string TrimLeft(const std::string& s)
    {
	size_t startpos = s.find_first_not_of(WHITESPACE);
	return (startpos == std::string::npos) ? "" : s.substr(startpos);
    }

    static std::string TrimRight(const std::string& s)
    {
	size_t endpos = s.find_last_not_of(WHITESPACE);
	return (endpos == std::string::npos) ? "" : s.substr(0, endpos + 1);
    }

    std::string trim(const std::string& s)
    {
	return TrimRight(TrimLeft(s));
    }

    int getIntProperty(rapidxml::xml_node<> *node, const char *name, int defaultValue = 0)
    {
	if (!node || !name)
	    return defaultValue;
	rapidxml::xml_attribute<> *result = 0;
	char *value = 0;

	result = node->first_attribute(name);
	if (!result)
	    return defaultValue;
	value = result->value();
	if (!value)
	    return defaultValue;
	return atoi(value);
    }

    float getFloatProperty(rapidxml::xml_node<> *node, const char *name, float defaultValue = 0)
    {
	if (!node || !name)
	    return defaultValue;
	rapidxml::xml_attribute<> *result = 0;
	char *value = 0;

	result = node->first_attribute(name);
	if (!result)
	    return defaultValue;
	value = result->value();
	if (!value)
	    return defaultValue;
	return (float) atof(value);
    }

    char *getStringProperty(rapidxml::xml_node<> *node, const char *name, char *defaultValue = (char *) "")
    {
	if (!node || !name)
	    return defaultValue;
	rapidxml::xml_attribute<> *result = 0;
	char *value = 0;

	result = node->first_attribute(name);
	if (!result)
	    return defaultValue;
	value = result->value();
	if (!value)
	    return defaultValue;
	return value;
    }

    void loadTiledProperties(IProperty *obj, rapidxml::xml_node<> *nodeNode)
    {
	rapidxml::xml_node<> *nodeProperties = 0;
	rapidxml::xml_node<> *nodeProperty = 0;

	nodeProperties = nodeNode->first_node("properties");
	if (nodeProperties)
	{
	    nodeProperty = nodeProperties->first_node("property");
	    while (nodeProperty)
	    {
		char *name = getStringProperty(nodeProperty, "name");
		char *value = getStringProperty(nodeProperty, "value");

		if (name && value)
		    obj->addProperty(name, value);
		nodeProperty = nodeProperty->next_sibling("property");
	    }
	}
    }

    Tileset *getTilesetFromGid(Map *map, int gid)
    {
	std::vector<Tileset *> tilesets = map->getTilesets();

	for (unsigned int i = 0; i < tilesets.size(); i++)
	{
	    Tileset *tileset = tilesets[i];
	    int limit = (tileset->getWidth() / (tileset->getTileWidth() + tileset->getSpacing())) * (tileset->getHeight() / (tileset->getTileHeight() + tileset->getSpacing()));

	    if (gid >= tileset->getFirstGid() && gid < tileset->getFirstGid() + limit)
		return tileset;
	}
	return 0;
    }

    int getTilePositionOnTilesetX(Tile *tile, Tileset *tileset)
    {
	int pos = (tile->getGid() - tileset->getFirstGid()) % (tileset->getWidth() / (tileset->getTileWidth() + tileset->getSpacing()));
	int space = tileset->getMargin() + tileset->getSpacing() * pos;

	return pos * tileset->getTileWidth() + space;
    }

    int getTilePositionOnTilesetY(Tile *tile, Tileset *tileset)
    {
	int pos = (tile->getGid() - tileset->getFirstGid()) / (tileset->getWidth() / (tileset->getTileHeight() + tileset->getSpacing()));
	int space = tileset->getMargin() + tileset->getSpacing() * pos;

	return pos * tileset->getTileHeight() + space;
    }

    void createTileFromGid(Map *map, Layer *layer, int gid, int iterator)
    {
	Tileset *tileset = getTilesetFromGid(map, gid);
	Tile *tile = new Tile();

	tile->setGid(gid);
	tile->setWidth(tileset->getTileWidth());
	tile->setHeight(tileset->getTileHeight());
	tile->setX((iterator % (layer->getWidth() / map->getTileWidth())) * tileset->getTileWidth() + tileset->getOffsetX());
	tile->setY((iterator / (layer->getWidth() / map->getTileHeight())) * tileset->getTileHeight() + tileset->getOffsetY());
	tile->setTilesetId(tileset->getId());
	tile->setTilesetX(getTilePositionOnTilesetX(tile, tileset));
	tile->setTilesetY(getTilePositionOnTilesetY(tile, tileset));
	layer->addTile(tile);
    }

}

#endif /* HELPER_HPP_ */
