/*
 * TiledMapLoader.h
 *
 *  Created on: 14 juil. 2013
 *      Author: picque_j
 */

#ifndef TILEDMAPLOADER_H_
#define TILEDMAPLOADER_H_

#include <vector>
#include <string>
#include "rapidxml/rapidxml.hpp"
#include "utils/NonCopyable.hpp"
#include "map/Map.h"
#include "map/Tileset.h"
#include "map/Layer.h"
#include "map/Tile.h"
#include "map/ObjectGroup.h"
#include "map/Object.h"

namespace Tiled
{

    class TiledMapLoader: private NonCopyable
    {
    public:
	TiledMapLoader();
	virtual ~TiledMapLoader();

	void loadFromFile(const std::string &);
	void loadFromText(const std::string &);
	Map *parseMap();
    private:
	void parseDocument();
	void parseTilesets(Map *, rapidxml::xml_node<> *);
	void parseTilesetsTileProperties(Map *, Tileset *, rapidxml::xml_node<> *);
	void parseLayers(Map *, rapidxml::xml_node<> *);
	void parseTiles(Map *, Layer *, rapidxml::xml_node<> *);
	void parseObjectGroup(Map *, rapidxml::xml_node<> *);
	void parseObject(Map *, ObjectGroup *, rapidxml::xml_node<> *);

	std::vector<Map *> _maps;
	rapidxml::xml_document<> _document;
	std::string _tiled;
    };

}
#endif /* TILEDMAPLOADER_H_ */
