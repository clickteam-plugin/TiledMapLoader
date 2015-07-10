#pragma once

#include <memory>

namespace TiledMapLoader {

	class Tile {
	public:
		using Ptr = std::unique_ptr<Tile>;

		unsigned getGid() const;
		void setGid(unsigned gid);
		int getFlippedDiagonally() const;
		void setFlippedDiagonally(int flippedDiagonally);
		int getFlippedHorizontally() const;
		void setFlippedHorizontally(int flippedHorizontally);
		int getFlippedVertically() const;
		void setFlippedVertically(int flippedVertically);
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
		int mFlippedHorizontally;
		int mFlippedVertically;
		int mFlippedDiagonally;
		int mWidth;
		int mHeight;
		int mX;
		int mY;
		int mTilesetId;
		int mTilesetX;
		int mTilesetY;
	};

}
