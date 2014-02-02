#pragma once

enum Events
{
	RAISE_ERROR,
	MAP_LOADED,
	PARSING_FINISHED,
	TILESET_LOADED,
	LAYER_LOADED,
	TILE_LOADED,
	OBJECT_GROUP_LOADED,
	OBJECT_LOADED
};

enum Actions
{
	LOAD_MAP,
	MAP_OFFSET
};

enum Expressions
{
	LAST_ERROR,
	MAP_WIDTH,
	MAP_HEIGHT,
	MAP_TILE_WIDTH,
	MAP_TILE_HEIGHT,
	MAP_ORIENTATION,
	MAP_VERSION,
	MAP_PROPERTY,
	TILESET_NAME,
	TILESET_IMAGE_PATH,
	TILESET_ID,
	TILESET_FIRST_GID,
	TILESET_WIDTH,
	TILESET_HEIGHT,
	TILESET_TILE_WIDTH,
	TILESET_TILE_HEIGHT,
	TILESET_SPACING,
	TILESET_MARGIN,
	TILESET_X_TILE_OFFSET,
	TILESET_Y_TILE_OFFSET,
	TILESET_PROPERTY,
	LAYER_NAME,
	LAYER_WIDTH,
	LAYER_HEIGHT,
	LAYER_OPACITY,
	LAYER_IS_VISIBLE,
	LAYER_PROPERTY,
	TILE_GID,
	TILE_WIDTH,
	TILE_HEIGHT,
	TILE_POS_MAP_X,
	TILE_POS_MAP_Y,
	TILE_ASSOC_TILESET_ID,
	TILE_POS_TILESET_X,
	TILE_POS_TILESET_Y,
	TILE_PROPERTY,
	OBJECT_GROUP_NAME,
	OBJECT_GROUP_DRAW_ORDER,
	OBJECT_GROUP_WIDTH,
	OBJECT_GROUP_HEIGHT,
	OBJECT_GROUP_OPACITY,
	OBJECT_GROUP_IS_VISIBLE,
	OBJECT_GROUP_PROPERTY,
	OBJECT_NAME,
	OBJECT_TYPE,
	OBJECT_POS_MAP_X,
	OBJECT_POS_MAP_Y,
	OBJECT_WIDTH,
	OBJECT_HEIGHT,
	OBJECT_ROTATION,
	OBJECT_GID,
	OBJECT_VERTICES,
	OBJECT_BOX2D_VERTICES,
	OBJECT_IS_POLYGON,
	OBJECT_IS_POLYLINE,
	OBJECT_IS_ELLIPSE,
	OBJECT_IS_FLIPPED_HORIZONTALLY,
	OBJECT_IS_FLIPPED_VERTICALLY,
	OBJECT_IS_FLIPPED_DIAGONALLY,
	OBJECT_IS_VISIBLE,
	OBJECT_PROPERTY
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

/// Events

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
int isObjctFlippedHorizontally();
int isObjctFlippedVertically();
int isObjctFlippedDiagonally();
int isObjectVisible();
char *getObjectProperty(char *, char *);