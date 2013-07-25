#include "Common.h"

Extension::Extension(LPRDATA _rdPtr, LPEDATA edPtr, fpcob cobPtr)
	: rdPtr(_rdPtr), rhPtr(_rdPtr->rHo.hoAdRunHeader), Runtime(_rdPtr)
{
	_offsetX = 0;
	_offsetY = 0;
	_lastError = 0;

	LinkAction(Actions::LOAD_MAP, loadMap);
	LinkAction(Actions::MAP_OFFSET, setMapOffset);

	LinkCondition(Events::RAISE_ERROR, onError);
	LinkCondition(Events::MAP_LOADED, onMapLoaded);
	LinkCondition(Events::PARSING_FINISHED, onParsingFinished);
	LinkCondition(Events::TILESET_LOADED, onTilesetLoaded);
	LinkCondition(Events::LAYER_LOADED, onLayerLoaded);
	LinkCondition(Events::TILE_LOADED, onTileLoaded);
	LinkCondition(Events::OBJECT_GROUP_LOADED, onObjectGroupLoaded);
	LinkCondition(Events::OBJECT_LOADED, onObjectLoaded);

	LinkExpression(Expressions::LAST_ERROR, getLastError);
	LinkExpression(Expressions::MAP_WIDTH, getMapWidth);
	LinkExpression(Expressions::MAP_HEIGHT, getMapHeight);
	LinkExpression(Expressions::MAP_TILE_WIDTH, getMapTileWidth);
	LinkExpression(Expressions::MAP_TILE_HEIGHT, getMapTileHeight);
	LinkExpression(Expressions::MAP_ORIENTATION, getMapOrientation);
	LinkExpression(Expressions::MAP_VERSION, getMapVersion);
	LinkExpression(Expressions::MAP_PROPERTY, getMapProperty);
	LinkExpression(Expressions::TILESET_NAME, getTilesetName);
	LinkExpression(Expressions::TILESET_IMAGE_PATH, getTilesetImagePath);
	LinkExpression(Expressions::TILESET_ID, getTilesetId);
	LinkExpression(Expressions::TILESET_FIRST_GID, getTilesetFirstGid);
	LinkExpression(Expressions::TILESET_WIDTH, getTilesetWidth);
	LinkExpression(Expressions::TILESET_HEIGHT, getTilesetHeight);
	LinkExpression(Expressions::TILESET_TILE_WIDTH, getTilesetTileWidth);
	LinkExpression(Expressions::TILESET_TILE_HEIGHT, getTilesetTileHeight);
	LinkExpression(Expressions::TILESET_SPACING, getTilesetSpacing);
	LinkExpression(Expressions::TILESET_MARGIN, getTilesetMargin);
	LinkExpression(Expressions::TILESET_X_TILE_OFFSET, getTilesetXTileOffset);
	LinkExpression(Expressions::TILESET_Y_TILE_OFFSET, getTilesetYTileOffset);
	LinkExpression(Expressions::TILESET_PROPERTY, getTilesetProperty);
	LinkExpression(Expressions::LAYER_NAME, getLayerName);
	LinkExpression(Expressions::LAYER_WIDTH, getLayerWidth);
	LinkExpression(Expressions::LAYER_HEIGHT, getLayerHeight);
	LinkExpression(Expressions::LAYER_OPACITY, getLayerOpacity);
	LinkExpression(Expressions::LAYER_IS_VISIBLE, isLayerVisible);
	LinkExpression(Expressions::LAYER_PROPERTY, getLayerProperty);
	LinkExpression(Expressions::TILE_GID, getTileGid);
	LinkExpression(Expressions::TILE_WIDTH, getTileWidth);
	LinkExpression(Expressions::TILE_HEIGHT, getTileHeight);
	LinkExpression(Expressions::TILE_POS_MAP_X, getTilePositionOnMapX);
	LinkExpression(Expressions::TILE_POS_MAP_Y, getTilePositionOnMapY);
	LinkExpression(Expressions::TILE_ASSOC_TILESET_ID, getTileAssociatedTilesetId);
	LinkExpression(Expressions::TILE_POS_TILESET_X, getTilePositionOnTilesetX);
	LinkExpression(Expressions::TILE_POS_TILESET_Y, getTilePositionOnTilesetY);
	LinkExpression(Expressions::TILE_PROPERTY, getTileProperty);
	LinkExpression(Expressions::OBJECT_GROUP_NAME, getObjectGroupName);
	LinkExpression(Expressions::OBJECT_GROUP_DRAW_ORDER, getObjectGroupDrawOrder);
	LinkExpression(Expressions::OBJECT_GROUP_WIDTH, getObjectGroupWidth);
	LinkExpression(Expressions::OBJECT_GROUP_HEIGHT, getObjectGroupHeight);
	LinkExpression(Expressions::OBJECT_GROUP_OPACITY, getObjectGroupOpacity);
	LinkExpression(Expressions::OBJECT_GROUP_IS_VISIBLE, isObjectGroupVisible);
	LinkExpression(Expressions::OBJECT_GROUP_PROPERTY, getObjectGroupProperty);
	LinkExpression(Expressions::OBJECT_NAME, getObjectName);
	LinkExpression(Expressions::OBJECT_TYPE, getObjectType);
	LinkExpression(Expressions::OBJECT_POS_MAP_X, getObjectPosOnMapX);
	LinkExpression(Expressions::OBJECT_POS_MAP_Y, getObjectPosOnMapY);
	LinkExpression(Expressions::OBJECT_WIDTH, getObjectWidth);
	LinkExpression(Expressions::OBJECT_HEIGHT, getObjectHeight);
	LinkExpression(Expressions::OBJECT_ROTATION, getObjectRotation);
	LinkExpression(Expressions::OBJECT_GID, getObjectTileGid);
	LinkExpression(Expressions::OBJECT_VERTICES, getObjectVertices);
	LinkExpression(Expressions::OBJECT_BOX2D_VERTICES, getObjectBox2DVertices);
	LinkExpression(Expressions::OBJECT_IS_POLYGON, isObjectPolygon);
	LinkExpression(Expressions::OBJECT_IS_POLYLINE, isObjectPolyline);
	LinkExpression(Expressions::OBJECT_IS_ELLIPSE, isObjectEllipse);
	LinkExpression(Expressions::OBJECT_IS_FLIPPED_HORIZONTALLY, isObjectVisible);
	LinkExpression(Expressions::OBJECT_IS_FLIPPED_VERTICALLY, isObjectVisible);
	LinkExpression(Expressions::OBJECT_IS_FLIPPED_DIAGONALLY, isObjectVisible);
	LinkExpression(Expressions::OBJECT_IS_VISIBLE, isObjectVisible);
	LinkExpression(Expressions::OBJECT_PROPERTY, getObjectProperty);
}

void Extension::raiseError(const char *error)
{
	_lastError = error;
	raiseEvent(Events::RAISE_ERROR);
}

void Extension::raiseEvent(int eventCode)
{
	Runtime.GenerateEvent(eventCode);
}

Extension::~Extension()
{
	if (_tiledMapLoader)
		delete _tiledMapLoader;
}

short Extension::Handle()
{
	return REFLAG_ONESHOT;
}


short Extension::Display()
{
	return 0;
}

short Extension::Pause()
{
	return 0;
}

short Extension::Continue()
{
	return 0;
}

bool Extension::Save(HANDLE File)
{
	bool OK = false;

#ifndef VITALIZE
	OK = true;
#endif

	return OK;
}

bool Extension::Load(HANDLE File)
{
	bool OK = false;

#ifndef VITALIZE
	OK = true;
#endif

	return OK;
}

void Extension::Action(int ID, LPRDATA rdPtr, long param1, long param2)
{

}

long Extension::Condition(int ID, LPRDATA rdPtr, long param1, long param2)
{
	return false;
}

long Extension::Expression(int ID, LPRDATA rdPtr, long param)
{
	return 0;
}

