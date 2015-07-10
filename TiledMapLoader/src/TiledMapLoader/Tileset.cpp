#include <TiledMapLoader/Tileset.h>

namespace TiledMapLoader {

	unsigned Tileset::getFirstGid() const {
		return mFirstGid;
	}

	void Tileset::setFirstGid(unsigned firstGid) {
		mFirstGid = firstGid;
	}

	int Tileset::getHeight() const {
		return mHeight;
	}

	void Tileset::setHeight(int height) {
		mHeight = height;
	}

	int Tileset::getId() const {
		return mId;
	}

	void Tileset::setId(int id) {
		mId = id;
	}

	const std::string &Tileset::getImageSource() const {
		return mImageSource;
	}

	void Tileset::setImageSource(const std::string &imageSource) {
		mImageSource = imageSource;
	}

	int Tileset::getMargin() const {
		return mMargin;
	}

	void Tileset::setMargin(int margin) {
		mMargin = margin;
	}

	const std::string &Tileset::getName() const {
		return mName;
	}

	void Tileset::setName(const std::string &name) {
		mName = name;
	}

	int Tileset::getOffsetX() const {
		return mOffsetX;
	}

	void Tileset::setOffsetX(int offsetX) {
		mOffsetX = offsetX;
	}

	int Tileset::getOffsetY() const {
		return mOffsetY;
	}

	void Tileset::setOffsetY(int offsetY) {
		mOffsetY = offsetY;
	}

	int Tileset::getSpacing() const {
		return mSpacing;
	}

	void Tileset::setSpacing(int spacing) {
		mSpacing = spacing;
	}

	int Tileset::getTileHeight() const {
		return mTileHeight;
	}

	void Tileset::setTileHeight(int tileHeight) {
		mTileHeight = tileHeight;
	}

	int Tileset::getTileWidth() const {
		return mTileWidth;
	}

	void Tileset::setTileWidth(int tileWidth) {
		mTileWidth = tileWidth;
	}

	int Tileset::getWidth() const {
		return mWidth;
	}

	void Tileset::setWidth(int width) {
		mWidth = width;
	}

	const std::map<int, std::map<std::string, std::string>> &Tileset::getTileProperties() const {
		return mTileProperties;
	}

	void TiledMapLoader::Tileset::addTileProperties(int tileId, const std::string &name, const std::string &value) {
		mTileProperties[tileId][name] = value;
	}

	int Tileset::getTilePositionOnTilesetX(const Tile &tile) const {
		auto pos = (tile.getGid() - getFirstGid()) % (getWidth() / (getTileWidth() + getSpacing()));
		auto space = getMargin() + getSpacing()  *pos;
		return pos  *getTileWidth() + space;
	}

	int Tileset::getTilePositionOnTilesetY(const Tile &tile) const {
		auto pos = (tile.getGid() - getFirstGid()) / (getWidth() / (getTileHeight() + getSpacing()));
		auto space = getMargin() + getSpacing()  *pos;
		return pos  *getTileHeight() + space;
	}

}
