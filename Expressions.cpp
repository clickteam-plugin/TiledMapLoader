#include "Common.h"

#define __(x) Runtime.CopyString(x)

char *Extension::getLastError() {
	if (!mLastError)
		return __("No errors");
	return __(mLastError);
}

int Extension::getMapWidth() {
	if (!mMap)
		return 0;
	return mMap->getWidth();
}

int Extension::getMapHeight() {
	if (!mMap)
		return 0;
	return mMap->getHeight();
}

int Extension::getMapTileWidth() {
	if (!mMap)
		return 0;
	return mMap->getTileWidth();
}

int Extension::getMapTileHeight() {
	if (!mMap)
		return 0;
	return mMap->getTileHeight();
}

char *Extension::getMapOrientation() {
	if (!mMap)
		return __("");
	return __(mMap->getOrientation().c_str());
}

char *Extension::getMapVersion() {
	if (!mMap)
		return __("");
	return __(mMap->getVersion().c_str());
}

char *Extension::getMapProperty(char *name, char *defaultValue) {
	if (!mMap)
		return __(defaultValue);
	std::map<std::string, std::string> properties = mMap->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return __(it->second.c_str());
	return __(defaultValue);
}

char *Extension::getTilesetName() {
	if (!mTileset)
		return __("");
	return __(mTileset->getName().c_str());
}

char *Extension::getTilesetImagePath() {
	if (!mTileset)
		return __("");
	return __(mTileset->getImageSource().c_str());
}

int Extension::getTilesetId() {
	if (!mTileset)
		return 0;
	return mTileset->getId();
}

int Extension::getTilesetFirstGid() {
	if (!mTileset)
		return 0;
	return mTileset->getFirstGid();
}

int Extension::getTilesetWidth() {
	if (!mTileset)
		return 0;
	return mTileset->getWidth();
}

int Extension::getTilesetHeight() {
	if (!mTileset)
		return 0;
	return mTileset->getHeight();
}

int Extension::getTilesetTileWidth() {
	if (!mTileset)
		return 0;
	return mTileset->getTileWidth();
}

int Extension::getTilesetTileHeight() {
	if (!mTileset)
		return 0;
	return mTileset->getTileHeight();
}

int Extension::getTilesetSpacing() {
	if (!mTileset)
		return 0;
	return mTileset->getSpacing();
}

int Extension::getTilesetMargin() {
	if (!mTileset)
		return 0;
	return mTileset->getMargin();
}

int Extension::getTilesetXTileOffset() {
	if (!mTileset)
		return 0;
	return mTileset->getOffsetX();
}

int Extension::getTilesetYTileOffset() {
	if (!mTileset)
		return 0;
	return mTileset->getOffsetY();

}

char *Extension::getTilesetProperty(char *name, char *defaultValue) {
	if (!mTileset)
		return __(defaultValue);
	std::map<std::string, std::string> properties = mTileset->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return __(it->second.c_str());
	return __(defaultValue);
}

char *Extension::getLayerName() {
	if (!mLayer)
		return 0;
	return __(mLayer->getName().c_str());
}

int Extension::getLayerWidth() {
	if (!mLayer)
		return 0;
	return mLayer->getWidth();
}

int Extension::getLayerHeight() {
	if (!mLayer)
		return 0;
	return mLayer->getHeight();
}

float Extension::getLayerOpacity() {
	if (!mLayer)
		return 1;
	return mLayer->getOpacity();
}

int Extension::isLayerVisible() {
	if (!mLayer)
		return 1;
	return mLayer->getVisible();
}

char *Extension::getLayerProperty(char *name, char *defaultValue) {
	if (!mLayer)
		return __(defaultValue);
	std::map<std::string, std::string> properties = mLayer->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return __(it->second.c_str());
	return __(defaultValue);
}

int Extension::getTileGid() {
	if (!mTile)
		return 0;
	return mTile->getGid();
}

int Extension::getTileWidth() {
	if (!mTile)
		return 0;
	return mTile->getWidth();
}

int Extension::getTileHeight() {
	if (!mTile)
		return 0;
	return mTile->getHeight();
}

int Extension::getTilePositionOnMapX() {
	if (!mTile)
		return 0;
	return mTile->getX() + mOffsetX;
}

int Extension::getTilePositionOnMapY() {
	if (!mTile)
		return 0;
	return mTile->getY() + mOffsetY;
}

int Extension::getTileAssociatedTilesetId() {
	if (!mTile)
		return 0;
	return mTile->getTilesetId();
}

int Extension::getTilePositionOnTilesetX() {
	if (!mTile)
		return 0;
	return mTile->getTilesetX();
}

int Extension::getTilePositionOnTilesetY() {
	if (!mTile)
		return 0;
	return mTile->getTilesetY();
}

int Extension::isTileFlippedHorizontally() {
	if (!mTile)
		return 0;
	return mTile->getFlippedHorizontally();
}

int Extension::isTileFlippedVertically() {
	if (!mTile)
		return 0;
	return mTile->getFlippedVertically();
}

int Extension::isTileFlippedDiagonally() {
	if (!mTile)
		return 0;
	return mTile->getFlippedDiagonally();
}

char *Extension::getTileProperty(char *name, char *defaultValue) {
	if (!mTile)
		return __(defaultValue);
	try {
		const auto &tileset = mMap->getTilesets().at(mTile->getTilesetId());
		if (!tileset)
			return __(defaultValue);
		std::map<std::string, std::string> properties = tileset->getTileProperties().at(mTile->getGid() - tileset->getFirstGid());

		std::map<std::string, std::string>::const_iterator it = properties.find(name);
		if (it != properties.end())
			return __(it->second.c_str());
		return __(defaultValue);
	}
	catch (std::out_of_range&) {
		return __(defaultValue);
	}
}

char *Extension::getObjectGroupName() {
	if (!mObjectGroup)
		return __("");
	return __(mObjectGroup->getName().c_str());
}

char *Extension::getObjectGroupDrawOrder() {
	if (!mObjectGroup)
		return __("");
	return __(mObjectGroup->getDrawOrder().c_str());
}

int Extension::getObjectGroupWidth() {
	if (!mObjectGroup)
		return 0;
	return mObjectGroup->getWidth();
}

int Extension::getObjectGroupHeight() {
	if (!mObjectGroup)
		return 0;
	return mObjectGroup->getHeight();
}

float Extension::getObjectGroupOpacity() {
	if (!mObjectGroup)
		return 1;
	return mObjectGroup->getOpacity();
}

int Extension::isObjectGroupVisible() {
	if (!mObjectGroup)
		return 1;
	return mObjectGroup->getVisible();
}

char *Extension::getObjectGroupProperty(char *name, char *defaultValue) {
	if (!mObjectGroup)
		return __(defaultValue);
	std::map<std::string, std::string> properties = mObjectGroup->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return __(it->second.c_str());
	return __(defaultValue);
}

char *Extension::getObjectName() {
	if (!mObject)
		return __("");
	return __(mObject->getName().c_str());
}

char *Extension::getObjectType() {
	if (!mObject)
		return __("");
	return __(mObject->getType().c_str());
}

int Extension::getObjectPosOnMapX() {
	if (!mObject)
		return 0;
	return (int) mObject->getX() + mOffsetX;
}

int Extension::getObjectPosOnMapY() {
	if (!mObject)
		return 0;
	return (int) mObject->getY() + mOffsetY;
}

float Extension::getObjectWidth() {
	if (!mObject)
		return 0;
	return mObject->getWidth();
}

float Extension::getObjectHeight() {
	if (!mObject)
		return 0;
	return mObject->getHeight();
}

float Extension::getObjectRotation() {
	if (!mObject)
		return 0;
	return mObject->getRotation();
}

int Extension::getObjectTileGid() {
	if (!mObject)
		return 0;
	return mObject->getGid();
}

char *Extension::getObjectVertices(char *defaultValue) {
	if (!mObject)
		return __(defaultValue);
	const char *vertices = mObject->getVertices().c_str();
	if (!vertices || !_strcmpi(vertices, __("")))
		return __(defaultValue);
	return __(vertices);
}

char *Extension::getObjectBox2DVertices(char *defaultValue) {
	if (!mObject)
		return __(defaultValue);
	char *vertices = __(mObject->getVertices().c_str());
	if (!vertices || !_strcmpi(vertices, __("")))
		return __(defaultValue);
	int i = 0;
	while (vertices[i] != '\0') {
		if (vertices[i] == ' ')
			vertices[i] = ',';
		++i;
	}
	return __(vertices);
}

int Extension::isObjectPolygon() {
	if (!mObject)
		return 0;
	return mObject->getPolygonType() == "polygon";
}

int Extension::isObjectPolyline() {
	if (!mObject)
		return 0;
	return mObject->getPolygonType() == "polyline";
}

int Extension::isObjectEllipse() {
	if (!mObject)
		return 0;
	return mObject->getPolygonType() == "ellipse";
}

int Extension::isObjectFlippedHorizontally() {
	if (!mObject)
		return 0;
	return mObject->getFlippedHorizontally();
}

int Extension::isObjectFlippedVertically() {
	if (!mObject)
		return 0;
	return mObject->getFlippedVertically();
}

int Extension::isObjectFlippedDiagonally() {
	if (!mObject)
		return 0;
	return mObject->getFlippedDiagonally();
}

int Extension::isObjectVisible() {
	if (!mObject)
		return 0;
	return mObject->getVisible();
}

char *Extension::getObjectProperty(char *name, char *defaultValue) {
	if (!mObject)
		return __(defaultValue);
	std::map<std::string, std::string> properties = mObject->getProperties();

	std::map<std::string, std::string>::const_iterator it = properties.find(name);
	if (it != properties.end())
		return __(it->second.c_str());
	return __(defaultValue);
}

int Extension::getObjectId() {
	if (!mObject)
		return -1;
	return mObject->getId();
}
