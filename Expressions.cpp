#include "Common.h"

char *Extension::getLastError()
{
	if (!_lastError)
		return "";
	return Runtime.CopyString(_lastError);
}

int Extension::getMapWidth()
{
	if (!_map)
		return 0;
	return _map->getWidth();
}

int Extension::getMapHeight()
{
	if (!_map)
		return 0;
	return _map->getHeight();
}

int Extension::getMapTileWidth()
{
	if (!_map)
		return 0;
	return _map->getTileWidth();
}

int Extension::getMapTileHeight()
{
	if (!_map)
		return 0;
	return _map->getTileHeight();
}

char *Extension::getMapOrientation()
{
	if (!_map)
		return "";
	return Runtime.CopyString(_map->getOrientation().c_str());
}

char *Extension::getMapVersion()
{
	if (!_map)
		return "";
	return Runtime.CopyString(_map->getVersion().c_str());
}

char *Extension::getMapProperty(char *name, char *defaultValue)
{
	if (!_map)
		return defaultValue;
	std::map<std::string, std::string> properties = _map->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return Runtime.CopyString(it->second.c_str());
	return defaultValue;
}


char *Extension::getTilesetName()
{
	if (!_tileset)
		return "";
	return Runtime.CopyString(_tileset->getName().c_str());
}

char *Extension::getTilesetImagePath()
{
	if (!_tileset)
		return "";
	return Runtime.CopyString(_tileset->getImageSource().c_str());
}

int Extension::getTilesetId()
{
	if (!_tileset)
		return 0;
	return _tileset->getId();
}

int Extension::getTilesetFirstGid()
{
	if (!_tileset)
		return 0;
	return _tileset->getFirstGid();
}

int Extension::getTilesetWidth()
{
	if (!_tileset)
		return 0;
	return _tileset->getWidth();
}

int Extension::getTilesetHeight()
{
	if (!_tileset)
		return 0;
	return _tileset->getHeight();
}

int Extension::getTilesetTileWidth()
{
	if (!_tileset)
		return 0;
	return _tileset->getTileWidth();
}

int Extension::getTilesetTileHeight()
{
	if (!_tileset)
		return 0;
	return _tileset->getTileHeight();
}

int Extension::getTilesetSpacing()
{
	if (!_tileset)
		return 0;
	return _tileset->getSpacing();
}

int Extension::getTilesetMargin()
{
	if (!_tileset)
		return 0;
	return _tileset->getMargin();
}

int Extension::getTilesetXTileOffset()
{
	if (!_tileset)
		return 0;
	return _tileset->getOffsetX();
}

int Extension::getTilesetYTileOffset()
{
	if (!_tileset)
		return 0;
	return _tileset->getOffsetY();

}

char *Extension::getTilesetProperty(char *name, char *defaultValue)
{
	if (!_tileset)
		return defaultValue;
	std::map<std::string, std::string> properties = _tileset->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return Runtime.CopyString(it->second.c_str());
	return defaultValue;
}

char *Extension::getLayerName()
{
	if (!_layer)
		return 0;
	return Runtime.CopyString(_layer->getName().c_str());
}

int Extension::getLayerWidth()
{
	if (!_layer)
		return 0;
	return _layer->getWidth();
}

int Extension::getLayerHeight()
{
	if (!_layer)
		return 0;
	return _layer->getHeight();
}

float Extension::getLayerOpacity()
{
	if (!_layer)
		return 1;
	return _layer->getOpacity();
}

int Extension::isLayerVisible()
{
	if (!_layer)
		return 1;
	return _layer->isVisible();
}

char *Extension::getLayerProperty(char *name, char *defaultValue)
{
	if (!_layer)
		return defaultValue;
	std::map<std::string, std::string> properties = _layer->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return Runtime.CopyString(it->second.c_str());
	return defaultValue;
}


int Extension::getTileGid()
{
	if (!_tile)
		return 0;
	return _tile->getGid();
}

int Extension::getTileWidth()
{
	if (!_tile)
		return 0;
	return _tile->getWidth();
}

int Extension::getTileHeight()
{
	if (!_tile)
		return 0;
	return _tile->getHeight();
}

int Extension::getTilePositionOnMapX()
{
	if (!_tile)
		return 0;
	return _tile->getX() + _offsetX;
}

int Extension::getTilePositionOnMapY()
{
	if (!_tile)
		return 0;
	return _tile->getY() + _offsetY;
}

int Extension::getTileAssociatedTilesetId()
{
	if (!_tile)
		return 0;
	return _tile->getTilesetId();
}

int Extension::getTilePositionOnTilesetX()
{
	if (!_tile)
		return 0;
	return _tile->getTilesetX();
}

int Extension::getTilePositionOnTilesetY()
{
	if (!_tile)
		return 0;
	return _tile->getTilesetY();
}

char *Extension::getTileProperty(char *name, char *defaultValue)
{
	if (!_tile)
		return defaultValue;
	try
	{
		Tiled::Tileset *tileset = _map->getTilesets().at(_tile->getTilesetId());
		if (!tileset)
			return defaultValue;
		std::map<std::string, std::string> properties = tileset->getTileProperties()[_tile->getGid() - tileset->getFirstGid()];

		std::map<std::string, std::string>::const_iterator it = properties.find(name);
		if (it != properties.end())
			return Runtime.CopyString(it->second.c_str());
		return defaultValue;
	}
	catch (std::out_of_range &)
	{
		return defaultValue;
	}
}

char *Extension::getObjectGroupName()
{
	if (!_objectGroup)
		return "";
	return Runtime.CopyString(_objectGroup->getName().c_str());
}

char *Extension::getObjectGroupDrawOrder()
{
	if (!_objectGroup)
		return "";
	return Runtime.CopyString(_objectGroup->getDrawOrder().c_str());
}

int Extension::getObjectGroupWidth()
{
	if (!_objectGroup)
		return 0;
	return _objectGroup->getWidth();
}

int Extension::getObjectGroupHeight()
{
	if (!_objectGroup)
		return 0;
	return _objectGroup->getHeight();
}

float Extension::getObjectGroupOpacity()
{
	if (!_objectGroup)
		return 1;
	return _objectGroup->getOpacity();
}

int Extension::isObjectGroupVisible()
{
	if (!_objectGroup)
		return 1;
	return _objectGroup->isVisible();
}

char *Extension::getObjectGroupProperty(char *name, char *defaultValue)
{
	if (!_objectGroup)
		return defaultValue;
	std::map<std::string, std::string> properties = _objectGroup->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return Runtime.CopyString(it->second.c_str());
	return defaultValue;
}

char *Extension::getObjectName()
{
	if (!_object)
		return "";
	return Runtime.CopyString(_object->getName().c_str());
}

char *Extension::getObjectType()
{
	if (!_object)
		return "";
	return Runtime.CopyString(_object->getType().c_str());
}

int Extension::getObjectPosOnMapX()
{
	if (!_object)
		return 0;
	return _object->getX() + _offsetX;
}

int Extension::getObjectPosOnMapY()
{
	if (!_object)
		return 0;
	return _object->getY() + _offsetY;
}

int Extension::getObjectWidth()
{
	if (!_object)
		return 0;
	return _object->getWidth();
}

int Extension::getObjectHeight()
{
	if (!_object)
		return 0;
	return _object->getHeight();
}

float Extension::getObjectRotation()
{
	if (!_object)
		return 0;
	return _object->getRotation();
}

int Extension::getObjectTileGid()
{
	if (!_object)
		return 0;
	return _object->getGid();
}

char *Extension::getObjectVertices(char *defaultValue)
{
	if (!_object)
		return defaultValue;
	const char *vertices = _object->getVertices().c_str();
	if (!vertices || !_strcmpi(vertices, ""))
		return defaultValue;
	return Runtime.CopyString(vertices);
}

char *Extension::getObjectBox2DVertices(char *defaultValue)
{
	if (!_object)
		return defaultValue;
	char *vertices = Runtime.CopyString(_object->getVertices().c_str());
	if (!vertices || !_strcmpi(vertices, ""))
		return defaultValue;
	int i = 0;
	while (vertices[i] != '\0')
	{
		if (vertices[i] == ' ')
			vertices[i] = ',';
		++i;
	}
	return vertices;
}

int Extension::isObjectPolygon()
{
	if (!_object)
		return 0;
	return _object->getPolygonType() == "polygon";
}

int Extension::isObjectPolyline()
{
	if (!_object)
		return 0;
	return _object->getPolygonType() == "polyline";
}

int Extension::isObjectEllipse()
{
	if (!_object)
		return 0;
	return _object->getPolygonType() == "ellipse";
}

int Extension::isObjctFlippedHorizontally()
{
	if (!_object)
		return 0;
	return _object->isFlippedHorizontally();
}

int Extension::isObjctFlippedVertically()
{
	if (!_object)
		return 0;
	return _object->isFlippedVertically();
}

int Extension::isObjctFlippedDiagonally()
{
	if (!_object)
		return 0;
	return _object->isFlippedDiagonally();
}

int Extension::isObjectVisible()
{
	if (!_object)
		return 0;
	return _object->isVisible();
}

char *Extension::getObjectProperty(char *name, char *defaultValue)
{
	if (!_object)
		return defaultValue;
	std::map<std::string, std::string> properties = _object->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return Runtime.CopyString(it->second.c_str());
	return defaultValue;
}
