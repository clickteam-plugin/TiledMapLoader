#pragma once

#include <memory>
#include <string>
#include <map>

#include <TiledMapLoader/Tile.h>
#include <TiledMapLoader/Property.h>

namespace TiledMapLoader
{

	class Tileset : public Property
	{
	public:
		typedef std::unique_ptr<Tileset> Ptr;

	public:
		unsigned getFirstGid() const;
		void setFirstGid(unsigned firstGid);
		int getHeight() const;
		void setHeight(int height);
		int getId() const;
		void setId(int id);
		const std::string& getImageSource() const;
		void setImageSource(const std::string& imageSource);
		int getMargin() const;
		void setMargin(int margin);
		const std::string& getName() const;
		void setName(const std::string& name);
		int getOffsetX() const;
		void setOffsetX(int offsetX);
		int getOffsetY() const;
		void setOffsetY(int offsetY);
		int getSpacing() const;
		void setSpacing(int spacing);
		int getTileHeight() const;
		void setTileHeight(int tileHeight);
		int getTileWidth() const;
		void setTileWidth(int tileWidth);
		int getWidth() const;
		void setWidth(int width);
		const std::map<int, std::map<std::string, std::string> >& getTileProperties() const;
		void addTileProperties(int tileId, const std::string &name, const std::string &value);

	public:
		int getTilePositionOnTilesetX(const Tile &tile) const;
		int getTilePositionOnTilesetY(const Tile &tile) const;

	private:
		std::map<int, std::map<std::string, std::string>> mTileProperties;
		std::string mName;
		std::string mImageSource;
		int mId;
		unsigned mFirstGid;
		int mWidth;
		int mHeight;
		int mTileWidth;
		int mTileHeight;
		int mSpacing;
		int mMargin;
		int mOffsetX;
		int mOffsetY;
	};

}
