#pragma once

#include <string>

#include "../lib/rapidxml/rapidxml.hpp"

#include <TiledMapLoader/Map.h>
#include <TiledMapLoader/XMLElement.h>

namespace TiledMapLoader
{

	class Tileset;
	class Layer;
	class ObjectGroup;

	class TiledMapLoader
	{
	public:
		Map::Ptr loadMap(const std::string &mapFile, const std::string &mapPath = ".");

	private:
		void changeCurrentDirectory(const std::string &mapPath);
		void restoreCurrentDirectory();

	private:
		void loadInternalMap(Map &map, char *xml);

	private:
		void loadTilesets(Map &map, rapidxml::xml_node<> &rootNode);
		void loadExternalTileset(Map &map, int tilesetId, const std::string &tilesetFile);
		void addTileset(Map &map, int tilesetId, rapidxml::xml_node<> &tilesetNode);
		void parseTilesetsTileProperties(Map &map, Tileset &tileset, rapidxml::xml_node<> &tilesetNode);
		void loadLayers(Map &map, rapidxml::xml_node<> &rootNode);
		void loadLayerTiles(Map &map, Layer &layer, rapidxml::xml_node<> &layerDataNode);
		void createTileFromGid(Map &map, Layer &layer, unsigned gid, unsigned mapIterator);
		void loadObjectGroups(Map &map, rapidxml::xml_node<> &rootNode);
		void loadObjectGroupObjects(Map &map, ObjectGroup &objectGroup, rapidxml::xml_node<> &objectGroupNode);

	private:
		char mCwd[1024];
	};

}
