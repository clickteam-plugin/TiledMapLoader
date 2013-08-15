#pragma once

#include <memory>
#include <vector>
#include <string>

#include <TiledMapLoader/Layer.h>
#include <TiledMapLoader/Property.h>
#include <TiledMapLoader/Tileset.h>
#include <TiledMapLoader/ObjectGroup.h>

namespace TiledMapLoader
{

	class Map: public Property
	{
	public:
		typedef std::unique_ptr<Map> Ptr;
		typedef std::vector<Tileset::Ptr> Tilesets;
		typedef std::vector<Layer::Ptr> Layers;
		typedef std::vector<ObjectGroup::Ptr> ObjectGroups;

	public:
		const Tilesets &getTilesets() const;
		const Layers &getLayers() const;
		const ObjectGroups &getObjectGroups() const;

	public:
		void addTileset(Tileset::Ptr tileset);
		void addLayer(Layer::Ptr layer);
		void addObjectGroup(ObjectGroup::Ptr objectGroup);

	public:
		int getHeight() const;
		void setHeight(int height);
		const std::string& getOrientation() const;
		void setOrientation(const std::string& orientation);
		int getTileHeight() const;
		void setTileHeight(int tileHeight);
		int getTileWidth() const;
		void setTileWidth(int tileWidth);
		const std::string& getVersion() const;
		void setVersion(const std::string& version);
		int getWidth() const;
		void setWidth(int width);

	public:
		const Tileset &getTilesetFromGid(unsigned gid) const;

	private:
		Tilesets mTilesets;
		Layers mLayers;
		ObjectGroups mObjectGroups;

	private:
		std::string mVersion;
		std::string mOrientation;
		int mWidth;
		int mHeight;
		int mTileWidth;
		int mTileHeight;
	};

}
