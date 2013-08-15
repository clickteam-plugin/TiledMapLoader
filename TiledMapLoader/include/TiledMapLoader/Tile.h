#pragma once

#include <memory>

namespace TiledMapLoader
{

	class Tile
	{
	public:
		typedef std::unique_ptr<Tile> Ptr;

		unsigned getGid() const;
		void setGid(unsigned gid);
		int getHeight() const;
		void setHeight(int height);
		int getTilesetId() const;
		void setTilesetId(int tilesetId);
		int getTilesetX() const;
		void setTilesetX(int tilesetX);
		int getTilesetY() const;
		void setTilesetY(int tilesetY);
		int getWidth() const;
		void setWidth(int width);
		int getX() const;
		void setX(int x);
		int getY() const;
		void setY(int y);

	private:
		unsigned mGid;
		int mWidth;
		int mHeight;
		int mX;
		int mY;
		int mTilesetId;
		int mTilesetX;
		int mTilesetY;
	};

}
