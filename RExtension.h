#pragma once

enum Conditions
{
	CONDITION_RAISE_ERROR = 0,
	CONDITION_MAP_LOADED,
	CONDITION_PARSING_FINISHED,
	CONDITION_TILESET_LOADED,
	CONDITION_LAYER_LOADED,
	CONDITION_TILE_LOADED,
	CONDITION_OBJECT_GROUP_LOADED,
	CONDITION_OBJECT_LOADED
};

enum Actions
{
	ACTION_LOAD_MAP = 0,
	ACTION_MAP_OFFSET
};

enum Expressions
{
	EXPRESSION_LAST_ERROR = 0,
	EXPRESSION_MAP_WIDTH,
	EXPRESSION_MAP_HEIGHT,
	EXPRESSION_MAP_TILE_WIDTH,
	EXPRESSION_MAP_TILE_HEIGHT,
	EXPRESSION_MAP_ORIENTATION,
	EXPRESSION_MAP_VERSION,
	EXPRESSION_MAP_PROPERTY,
	EXPRESSION_TILESET_NAME,
	EXPRESSION_TILESET_IMAGE_PATH,
	EXPRESSION_TILESET_ID,
	EXPRESSION_TILESET_FIRST_GID,
	EXPRESSION_TILESET_WIDTH,
	EXPRESSION_TILESET_HEIGHT,
	EXPRESSION_TILESET_TILE_WIDTH,
	EXPRESSION_TILESET_TILE_HEIGHT,
	EXPRESSION_TILESET_SPACING,
	EXPRESSION_TILESET_MARGIN,
	EXPRESSION_TILESET_X_TILE_OFFSET,
	EXPRESSION_TILESET_Y_TILE_OFFSET,
	EXPRESSION_TILESET_PROPERTY,
	EXPRESSION_LAYER_NAME,
	EXPRESSION_LAYER_WIDTH,
	EXPRESSION_LAYER_HEIGHT,
	EXPRESSION_LAYER_OPACITY,
	EXPRESSION_LAYER_IS_VISIBLE,
	EXPRESSION_LAYER_PROPERTY,
	EXPRESSION_TILE_GID,
	EXPRESSION_TILE_WIDTH,
	EXPRESSION_TILE_HEIGHT,
	EXPRESSION_TILE_POS_MAP_X,
	EXPRESSION_TILE_POS_MAP_Y,
	EXPRESSION_TILE_ASSOC_TILESET_ID,
	EXPRESSION_TILE_POS_TILESET_X,
	EXPRESSION_TILE_POS_TILESET_Y,
	EXPRESSION_TILE_PROPERTY,
	EXPRESSION_OBJECT_GROUP_NAME,
	EXPRESSION_OBJECT_GROUP_DRAW_ORDER,
	EXPRESSION_OBJECT_GROUP_WIDTH,
	EXPRESSION_OBJECT_GROUP_HEIGHT,
	EXPRESSION_OBJECT_GROUP_OPACITY,
	EXPRESSION_OBJECT_GROUP_IS_VISIBLE,
	EXPRESSION_OBJECT_GROUP_PROPERTY,
	EXPRESSION_OBJECT_NAME,
	EXPRESSION_OBJECT_TYPE,
	EXPRESSION_OBJECT_POS_MAP_X,
	EXPRESSION_OBJECT_POS_MAP_Y,
	EXPRESSION_OBJECT_WIDTH,
	EXPRESSION_OBJECT_HEIGHT,
	EXPRESSION_OBJECT_ROTATION,
	EXPRESSION_OBJECT_GID,
	EXPRESSION_OBJECT_VERTICES,
	EXPRESSION_OBJECT_BOX2D_VERTICES,
	EXPRESSION_OBJECT_IS_POLYGON,
	EXPRESSION_OBJECT_IS_POLYLINE,
	EXPRESSION_OBJECT_IS_ELLIPSE,
	EXPRESSION_OBJECT_IS_FLIPPED_HORIZONTALLY,
	EXPRESSION_OBJECT_IS_FLIPPED_VERTICALLY,
	EXPRESSION_OBJECT_IS_FLIPPED_DIAGONALLY,
	EXPRESSION_OBJECT_IS_VISIBLE,
	EXPRESSION_OBJECT_PROPERTY,
	EXPRESSION_OBJECT_ID,
	EXPRESSION_TILE_IS_FLIPPED_HORIZONTALLY,
	EXPRESSION_TILE_IS_FLIPPED_VERTICALLY,
	EXPRESSION_TILE_IS_FLIPPED_DIAGONALLY
};

/// Members

int mOffsetX;
int mOffsetY;
TiledMapLoader::Map *mMap;
TiledMapLoader::Tileset *mTileset;
TiledMapLoader::Layer *mLayer;
TiledMapLoader::Tile *mTile;
TiledMapLoader::ObjectGroup *mObjectGroup;
TiledMapLoader::Object *mObject;

/// Error handling

const char *mLastError;
void raiseError(const char *);

/// Raise condition as event

void raiseEvent(int eventCode);

/// Actions

void loadMap(char *);
void setMapOffset(int, int);

/// Conditions

bool onError();
bool onMapLoaded();
bool onParsingFinished();
bool onTilesetLoaded();
bool onLayerLoaded();
bool onTileLoaded();
bool onObjectGroupLoaded();
bool onObjectLoaded();

/// Expressions

char *getLastError();

int getMapWidth();
int getMapHeight();
int getMapTileWidth();
int getMapTileHeight();
char *getMapOrientation();
char *getMapVersion();
char *getMapProperty(char *, char *);

char *getTilesetName();
char *getTilesetImagePath();
int getTilesetId();
int getTilesetFirstGid();
int getTilesetWidth();
int getTilesetHeight();
int getTilesetTileWidth();
int getTilesetTileHeight();
int getTilesetSpacing();
int getTilesetMargin();
int getTilesetXTileOffset();
int getTilesetYTileOffset();
char *getTilesetProperty(char *, char *);

char *getLayerName();
int getLayerWidth();
int getLayerHeight();
float getLayerOpacity();
int isLayerVisible();
char *getLayerProperty(char *, char *);

int getTileGid();
int getTileWidth();
int getTileHeight();
int getTilePositionOnMapX();
int getTilePositionOnMapY();
int getTileAssociatedTilesetId();
int getTilePositionOnTilesetX();
int getTilePositionOnTilesetY();
int isTileFlippedHorizontally();
int isTileFlippedVertically();
int isTileFlippedDiagonally();
char *getTileProperty(char *, char *);

char *getObjectGroupName();
char *getObjectGroupDrawOrder();
int getObjectGroupWidth();
int getObjectGroupHeight();
float getObjectGroupOpacity();
int isObjectGroupVisible();
char *getObjectGroupProperty(char *, char *);

char *getObjectName();
char *getObjectType();
int getObjectPosOnMapX();
int getObjectPosOnMapY();
int getObjectWidth();
int getObjectHeight();
float getObjectRotation();
int getObjectTileGid();
char *getObjectVertices(char *);
char *getObjectBox2DVertices(char *);
int isObjectPolygon();
int isObjectPolyline();
int isObjectEllipse();
int isObjectFlippedHorizontally();
int isObjectFlippedVertically();
int isObjectFlippedDiagonally();
int isObjectVisible();
char *getObjectProperty(char *, char *);
int getObjectId();