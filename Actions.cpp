#include "Common.h"

std::string getPathFromFile(const std::string &mapFile) {
	auto found = mapFile.find_last_of("/\\");
	return mapFile.substr(0, found);
}

void Extension::loadMap(char *mapFile) {
	try {
		TiledMapLoader::Map::Ptr map;
		TiledMapLoader::TiledMapLoader loader;
		map = loader.loadMap(mapFile, getPathFromFile(mapFile));
		mMap = map.get();
		raiseEvent(Conditions::CONDITION_MAP_LOADED);
		const auto &tilesets = map->getTilesets();
		const auto &layers = map->getLayers();
		const auto &objectGroups = map->getObjectGroups();
		for (const auto &tileset : tilesets) {
			mTileset = tileset.get();
			raiseEvent(Conditions::CONDITION_TILESET_LOADED);
		}
		for (const auto &layer : layers) {
			mLayer = layer.get();
			raiseEvent(Conditions::CONDITION_LAYER_LOADED);
			const auto &tiles = layer->getTiles();
			for (const auto &tile : tiles) {
				mTile = tile.get();
				raiseEvent(Conditions::CONDITION_TILE_LOADED);
			}
		}
		for (const auto &objectGroup : objectGroups) {
			mObjectGroup = objectGroup.get();
			raiseEvent(Conditions::CONDITION_OBJECT_GROUP_LOADED);
			const auto &objects = objectGroup->getObjects();
			for (const auto &object : objects) {
				mObject = object.get();
				raiseEvent(Conditions::CONDITION_OBJECT_LOADED);
			}
		}
		raiseEvent(Conditions::CONDITION_PARSING_FINISHED);
	}
	catch (std::exception &exception) {
		mLastError = exception.what();
		raiseEvent(Conditions::CONDITION_RAISE_ERROR);
	}
}

void Extension::setMapOffset(int offsetX, int offsetY) {
	mOffsetX = offsetX;
	mOffsetY = offsetY;
}
