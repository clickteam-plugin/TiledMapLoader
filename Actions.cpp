#include "Common.h"

std::string getPathFromFile(const std::string &mapFile)
{
	std::size_t found = mapFile.find_last_of("/\\");

	return mapFile.substr(0, found);
}

void Extension::loadMap(char *mapFile)
{
	try
	{
		TiledMapLoader::Map::Ptr map;
		TiledMapLoader::TiledMapLoader loader;

		map = loader.loadMap(mapFile, getPathFromFile(mapFile));
		mMap = map.get();
		raiseEvent(Events::MAP_LOADED);

		const auto &tilesets = map->getTilesets();
		const auto &layers = map->getLayers();
		const auto &objectGroups = map->getObjectGroups();

		for (const auto &tileset : tilesets)
		{
			mTileset = tileset.get();
			raiseEvent(Events::TILESET_LOADED);
		}
		for (const auto &layer : layers)
		{
			mLayer = layer.get();
			raiseEvent(Events::LAYER_LOADED);

			const auto &tiles = layer->getTiles();

			for (const auto &tile : tiles)
			{
				mTile = tile.get();
				raiseEvent(Events::TILE_LOADED);
			}
		}
		for (const auto &objectGroup : objectGroups)
		{
			mObjectGroup = objectGroup.get();
			raiseEvent(Events::OBJECT_GROUP_LOADED);

			const auto &objects = objectGroup->getObjects();

			for (const auto &object : objects)
			{
				mObject = object.get();
				raiseEvent(Events::OBJECT_LOADED);
			}
		}
		raiseEvent(Events::PARSING_FINISHED);
	}
	catch (std::exception &exception)
	{
		mLastError = exception.what();
		raiseEvent(Events::RAISE_ERROR);
	}
}

void Extension::setMapOffset(int offsetX, int offsetY)
{
	mOffsetX = offsetX;
	mOffsetY = offsetY;
}