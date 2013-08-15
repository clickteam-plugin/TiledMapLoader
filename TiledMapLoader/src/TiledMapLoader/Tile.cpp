#include <TiledMapLoader/Tile.h>

namespace TiledMapLoader
{

	unsigned Tile::getGid() const
	{
		return mGid;
	}

	void Tile::setGid(unsigned gid)
	{
		mGid = gid;
	}

	int Tile::getHeight() const
	{
		return mHeight;
	}

	void Tile::setHeight(int height)
	{
		mHeight = height;
	}

	int Tile::getTilesetId() const
	{
		return mTilesetId;
	}

	void Tile::setTilesetId(int tilesetId)
	{
		mTilesetId = tilesetId;
	}

	int Tile::getTilesetX() const
	{
		return mTilesetX;
	}

	void Tile::setTilesetX(int tilesetX)
	{
		mTilesetX = tilesetX;
	}

	int Tile::getTilesetY() const
	{
		return mTilesetY;
	}

	void Tile::setTilesetY(int tilesetY)
	{
		mTilesetY = tilesetY;
	}

	int Tile::getWidth() const
	{
		return mWidth;
	}

	void Tile::setWidth(int width)
	{
		mWidth = width;
	}

	int Tile::getX() const
	{
		return mX;
	}

	void Tile::setX(int x)
	{
		mX = x;
	}

	int Tile::getY() const
	{
		return mY;
	}

	void Tile::setY(int y)
	{
		mY = y;
	}

}
