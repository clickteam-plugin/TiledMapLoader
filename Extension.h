
class Extension
{
public:

	LPRDATA rdPtr;
	LPRH    rhPtr;

	Edif::Runtime Runtime;

	static const int MinimumBuild = 248;
	static const int Version = 1;

	static const int OEFLAGS = OEFLAG_VALUES | OEFLAG_RUNBEFOREFADEIN | OEFLAG_NEVERKILL;
	static const int OEPREFS = 0;

	static const int WindowProcPriority = 100;

	Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
	~Extension();

	/// Members

	int _offsetX;
	int _offsetY;
	Tiled::TiledMapLoader *_tiledMapLoader;
	Tiled::Map *_map;
	Tiled::Tileset *_tileset;
	Tiled::Layer *_layer;
	Tiled::Tile *_tile;
	Tiled::ObjectGroup *_objectGroup;
	Tiled::Object *_object;

	/// Error handling

	const char *_lastError;
	void raiseError(const char *);

	/// Events

	void raiseEvent(int eventCode);
	void startParsing();

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
	virtual int isObjectPolygon();
	int isObjectPolyline();
	int isObjectEllipse();
	int isObjctFlippedHorizontally();
	int isObjctFlippedVertically();
	int isObjctFlippedDiagonally();
	int isObjectVisible();
	char *getObjectProperty(char *, char *);

	/// Extension SDK

	void Action(int ID, LPRDATA rdPtr, long param1, long param2);
	long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
	long Expression(int ID, LPRDATA rdPtr, long param);

	short Handle();
	short Display();

	short Pause();
	short Continue();

	bool Save(HANDLE File);
	bool Load(HANDLE File);

};