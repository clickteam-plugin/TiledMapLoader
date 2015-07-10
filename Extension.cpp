#include "Common.h"

Extension::Extension(LPRDATA _rdPtr, LPEDATA edPtr, fpcob cobPtr)
	: rdPtr(_rdPtr), rhPtr(_rdPtr->rHo.hoAdRunHeader), Runtime(_rdPtr) {
	mOffsetX = 0;
	mOffsetY = 0;
	mLastError = nullptr;

	LinkAction(Actions::ACTION_LOAD_MAP, loadMap);
	LinkAction(Actions::ACTION_MAP_OFFSET, setMapOffset);

	LinkCondition(Conditions::CONDITION_RAISE_ERROR, onError);
	LinkCondition(Conditions::CONDITION_MAP_LOADED, onMapLoaded);
	LinkCondition(Conditions::CONDITION_PARSING_FINISHED, onParsingFinished);
	LinkCondition(Conditions::CONDITION_TILESET_LOADED, onTilesetLoaded);
	LinkCondition(Conditions::CONDITION_LAYER_LOADED, onLayerLoaded);
	LinkCondition(Conditions::CONDITION_TILE_LOADED, onTileLoaded);
	LinkCondition(Conditions::CONDITION_OBJECT_GROUP_LOADED, onObjectGroupLoaded);
	LinkCondition(Conditions::CONDITION_OBJECT_LOADED, onObjectLoaded);

	LinkExpression(Expressions::EXPRESSION_LAST_ERROR, getLastError);
	LinkExpression(Expressions::EXPRESSION_MAP_WIDTH, getMapWidth);
	LinkExpression(Expressions::EXPRESSION_MAP_HEIGHT, getMapHeight);
	LinkExpression(Expressions::EXPRESSION_MAP_TILE_WIDTH, getMapTileWidth);
	LinkExpression(Expressions::EXPRESSION_MAP_TILE_HEIGHT, getMapTileHeight);
	LinkExpression(Expressions::EXPRESSION_MAP_ORIENTATION, getMapOrientation);
	LinkExpression(Expressions::EXPRESSION_MAP_VERSION, getMapVersion);
	LinkExpression(Expressions::EXPRESSION_MAP_PROPERTY, getMapProperty);
	LinkExpression(Expressions::EXPRESSION_TILESET_NAME, getTilesetName);
	LinkExpression(Expressions::EXPRESSION_TILESET_IMAGE_PATH, getTilesetImagePath);
	LinkExpression(Expressions::EXPRESSION_TILESET_ID, getTilesetId);
	LinkExpression(Expressions::EXPRESSION_TILESET_FIRST_GID, getTilesetFirstGid);
	LinkExpression(Expressions::EXPRESSION_TILESET_WIDTH, getTilesetWidth);
	LinkExpression(Expressions::EXPRESSION_TILESET_HEIGHT, getTilesetHeight);
	LinkExpression(Expressions::EXPRESSION_TILESET_TILE_WIDTH, getTilesetTileWidth);
	LinkExpression(Expressions::EXPRESSION_TILESET_TILE_HEIGHT, getTilesetTileHeight);
	LinkExpression(Expressions::EXPRESSION_TILESET_SPACING, getTilesetSpacing);
	LinkExpression(Expressions::EXPRESSION_TILESET_MARGIN, getTilesetMargin);
	LinkExpression(Expressions::EXPRESSION_TILESET_X_TILE_OFFSET, getTilesetXTileOffset);
	LinkExpression(Expressions::EXPRESSION_TILESET_Y_TILE_OFFSET, getTilesetYTileOffset);
	LinkExpression(Expressions::EXPRESSION_TILESET_PROPERTY, getTilesetProperty);
	LinkExpression(Expressions::EXPRESSION_LAYER_NAME, getLayerName);
	LinkExpression(Expressions::EXPRESSION_LAYER_WIDTH, getLayerWidth);
	LinkExpression(Expressions::EXPRESSION_LAYER_HEIGHT, getLayerHeight);
	LinkExpression(Expressions::EXPRESSION_LAYER_OPACITY, getLayerOpacity);
	LinkExpression(Expressions::EXPRESSION_LAYER_IS_VISIBLE, isLayerVisible);
	LinkExpression(Expressions::EXPRESSION_LAYER_PROPERTY, getLayerProperty);
	LinkExpression(Expressions::EXPRESSION_TILE_GID, getTileGid);
	LinkExpression(Expressions::EXPRESSION_TILE_WIDTH, getTileWidth);
	LinkExpression(Expressions::EXPRESSION_TILE_HEIGHT, getTileHeight);
	LinkExpression(Expressions::EXPRESSION_TILE_POS_MAP_X, getTilePositionOnMapX);
	LinkExpression(Expressions::EXPRESSION_TILE_POS_MAP_Y, getTilePositionOnMapY);
	LinkExpression(Expressions::EXPRESSION_TILE_ASSOC_TILESET_ID, getTileAssociatedTilesetId);
	LinkExpression(Expressions::EXPRESSION_TILE_POS_TILESET_X, getTilePositionOnTilesetX);
	LinkExpression(Expressions::EXPRESSION_TILE_POS_TILESET_Y, getTilePositionOnTilesetY);
	LinkExpression(Expressions::EXPRESSION_TILE_IS_FLIPPED_HORIZONTALLY, isTileFlippedHorizontally);
	LinkExpression(Expressions::EXPRESSION_TILE_IS_FLIPPED_VERTICALLY, isTileFlippedHorizontally);
	LinkExpression(Expressions::EXPRESSION_TILE_IS_FLIPPED_DIAGONALLY, isTileFlippedDiagonally);
	LinkExpression(Expressions::EXPRESSION_TILE_PROPERTY, getTileProperty);
	LinkExpression(Expressions::EXPRESSION_OBJECT_GROUP_NAME, getObjectGroupName);
	LinkExpression(Expressions::EXPRESSION_OBJECT_GROUP_DRAW_ORDER, getObjectGroupDrawOrder);
	LinkExpression(Expressions::EXPRESSION_OBJECT_GROUP_WIDTH, getObjectGroupWidth);
	LinkExpression(Expressions::EXPRESSION_OBJECT_GROUP_HEIGHT, getObjectGroupHeight);
	LinkExpression(Expressions::EXPRESSION_OBJECT_GROUP_OPACITY, getObjectGroupOpacity);
	LinkExpression(Expressions::EXPRESSION_OBJECT_GROUP_IS_VISIBLE, isObjectGroupVisible);
	LinkExpression(Expressions::EXPRESSION_OBJECT_GROUP_PROPERTY, getObjectGroupProperty);
	LinkExpression(Expressions::EXPRESSION_OBJECT_NAME, getObjectName);
	LinkExpression(Expressions::EXPRESSION_OBJECT_TYPE, getObjectType);
	LinkExpression(Expressions::EXPRESSION_OBJECT_POS_MAP_X, getObjectPosOnMapX);
	LinkExpression(Expressions::EXPRESSION_OBJECT_POS_MAP_Y, getObjectPosOnMapY);
	LinkExpression(Expressions::EXPRESSION_OBJECT_WIDTH, getObjectWidth);
	LinkExpression(Expressions::EXPRESSION_OBJECT_HEIGHT, getObjectHeight);
	LinkExpression(Expressions::EXPRESSION_OBJECT_ROTATION, getObjectRotation);
	LinkExpression(Expressions::EXPRESSION_OBJECT_GID, getObjectTileGid);
	LinkExpression(Expressions::EXPRESSION_OBJECT_VERTICES, getObjectVertices);
	LinkExpression(Expressions::EXPRESSION_OBJECT_BOX2D_VERTICES, getObjectBox2DVertices);
	LinkExpression(Expressions::EXPRESSION_OBJECT_IS_POLYGON, isObjectPolygon);
	LinkExpression(Expressions::EXPRESSION_OBJECT_IS_POLYLINE, isObjectPolyline);
	LinkExpression(Expressions::EXPRESSION_OBJECT_IS_ELLIPSE, isObjectEllipse);
	LinkExpression(Expressions::EXPRESSION_OBJECT_IS_FLIPPED_HORIZONTALLY, isObjectFlippedHorizontally);
	LinkExpression(Expressions::EXPRESSION_OBJECT_IS_FLIPPED_VERTICALLY, isObjectFlippedVertically);
	LinkExpression(Expressions::EXPRESSION_OBJECT_IS_FLIPPED_DIAGONALLY, isObjectFlippedDiagonally);
	LinkExpression(Expressions::EXPRESSION_OBJECT_IS_VISIBLE, isObjectVisible);
	LinkExpression(Expressions::EXPRESSION_OBJECT_PROPERTY, getObjectProperty);
	LinkExpression(Expressions::EXPRESSION_OBJECT_ID, getObjectId);
}

void Extension::raiseError(const char *error) {
	mLastError = error;
	raiseEvent(Conditions::CONDITION_RAISE_ERROR);
}

void Extension::raiseEvent(int eventCode) {
	Runtime.GenerateEvent(eventCode);
}

Extension::~Extension() {

}

short Extension::Handle() {
	return REFLAG_ONESHOT;
}


short Extension::Display() {
	return 0;
}

short Extension::Pause() {
	return 0;
}

short Extension::Continue() {
	return 0;
}

bool Extension::Save(HANDLE File) {
	bool OK = false;

#ifndef VITALIZE
	OK = true;
#endif

	return OK;
}

bool Extension::Load(HANDLE File) {
	bool OK = false;

#ifndef VITALIZE
	OK = true;
#endif

	return OK;
}

void Extension::Action(int ID, LPRDATA rdPtr, long param1, long param2) {

}

long Extension::Condition(int ID, LPRDATA rdPtr, long param1, long param2) {
	return false;
}

long Extension::Expression(int ID, LPRDATA rdPtr, long param) {
	return 0;
}
