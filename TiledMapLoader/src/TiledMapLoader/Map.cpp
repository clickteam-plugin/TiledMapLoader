#include <stdexcept>

#include <TiledMapLoader/Map.h>

namespace TiledMapLoader {

	const std::vector<Tileset::Ptr> &Map::getTilesets() const {
		return mTilesets;
	}

	const std::vector<Layer::Ptr> &Map::getLayers() const {
		return mLayers;
	}

	const std::vector<ObjectGroup::Ptr> &Map::getObjectGroups() const {
		return mObjectGroups;
	}

	int Map::getHeight() const {
		return mHeight;
	}

	void Map::setHeight(int height) {
		mHeight = height;
	}

	const std::string &Map::getOrientation() const {
		return mOrientation;
	}

	void Map::setOrientation(const std::string &orientation) {
		mOrientation = orientation;
	}

	int Map::getTileHeight() const {
		return mTileHeight;
	}

	void Map::setTileHeight(int tileHeight) {
		mTileHeight = tileHeight;
	}

	int Map::getTileWidth() const {
		return mTileWidth;
	}

	void Map::setTileWidth(int tileWidth) {
		mTileWidth = tileWidth;
	}

	const std::string &Map::getVersion() const {
		return mVersion;
	}

	void Map::setVersion(const std::string &version) {
		mVersion = version;
	}

	int Map::getWidth() const {
		return mWidth;
	}

	void Map::addTileset(Tileset::Ptr tileset) {
		mTilesets.push_back(std::move(tileset));
	}

	void Map::addLayer(Layer::Ptr layer) {
		mLayers.push_back(std::move(layer));
	}

	void Map::addObjectGroup(ObjectGroup::Ptr objectGroup) {
		mObjectGroups.push_back(std::move(objectGroup));
	}

	void Map::setWidth(int width) {
		mWidth = width;
	}

	//TODO: Optimize this code
	const Tileset &Map::getTilesetFromGid(unsigned gid) const {
		for (const Tileset::Ptr &tileset : mTilesets) {
			int limit = (tileset->getWidth() / (tileset->getTileWidth() + tileset->getSpacing()))  *(tileset->getHeight() / (tileset->getTileHeight() + tileset->getSpacing()));
			if (gid >= tileset->getFirstGid() && gid < tileset->getFirstGid() + limit) {
				return *(tileset.get());
			}
		}
		throw std::logic_error("Tileset not found");
	}

}
