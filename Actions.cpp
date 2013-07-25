#include "Common.h"

void Extension::loadMap(char *mapFile)
{
	try
	{
		_tiledMapLoader = new Tiled::TiledMapLoader();
		if (!_tiledMapLoader)
			throw std::logic_error("Can't allocate memory");
		_tiledMapLoader->loadFromFile(mapFile);
		startParsing();
	}
	catch (std::logic_error &error)
	{
		raiseError(error.what());
	}
	delete _tiledMapLoader;
	_tiledMapLoader = 0;
}

void Extension::startParsing()
{
	_map = _tiledMapLoader->parseMap();
	raiseEvent(Events::MAP_LOADED);
	std::vector<Tiled::Tileset *> tilesets = _map->getTilesets();
	std::vector<Tiled::Layer *> layers = _map->getLayers();
	std::vector<Tiled::ObjectGroup *> objectGroups = _map->getObjectGroups();

	for (auto it = tilesets.begin(); it != tilesets.end(); ++it)
	{
		_tileset = *it;
		raiseEvent(Events::TILESET_LOADED);
	}
	for (auto it = layers.begin(); it != layers.end(); ++it)
	{
		_layer = *it;
		raiseEvent(Events::LAYER_LOADED);
		std::vector<Tiled::Tile *> tiles = _layer->getTiles();
		for (auto it_tile = tiles.begin(); it_tile != tiles.end(); ++it_tile)
		{
			_tile = *it_tile;
			raiseEvent(Events::TILE_LOADED);
		}
	}
	for (auto it = objectGroups.begin(); it != objectGroups.end(); ++it)
	{
		_objectGroup = *it;
		raiseEvent(Events::OBJECT_GROUP_LOADED);
		std::vector<Tiled::Object *> objects = _objectGroup->getObjects();
		for (auto it_object = objects.begin(); it_object != objects.end(); ++it_object)
		{
			_object = *it_object;
			raiseEvent(Events::OBJECT_LOADED);
		}
	}
	raiseEvent(Events::PARSING_FINISHED);
}

void Extension::setMapOffset(int offsetX, int offsetY)
{
	_offsetX = offsetX;
	_offsetY = offsetY;
}