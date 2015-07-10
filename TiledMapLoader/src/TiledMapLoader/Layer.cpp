#include <TiledMapLoader/Layer.h>

namespace TiledMapLoader {

	int Layer::getHeight() const {
		return mHeight;
	}

	void Layer::setHeight(int height) {
		mHeight = height;
	}

	const std::string &Layer::getName() const {
		return mName;
	}

	void Layer::setName(const std::string &name) {
		mName = name;
	}

	float Layer::getOpacity() const {
		return mOpacity;
	}

	void Layer::setOpacity(float opacity) {
		mOpacity = opacity;
	}

	int Layer::getVisible() const {
		return mVisible;
	}

	void Layer::setVisible(int visible) {
		mVisible = visible;
	}

	int Layer::getWidth() const {
		return mWidth;
	}

	void Layer::setWidth(int width) {
		mWidth = width;
	}

	int Layer::getId() const {
		return mId;
	}

	void Layer::setId(int id) {
		mId = id;
	}

	const Layer::Tiles &Layer::getTiles() const {
		return mTiles;
	}

	void Layer::addTile(Tile::Ptr tile) {
		mTiles.push_back(std::move(tile));
	}

}
