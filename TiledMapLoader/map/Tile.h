/*
 * Tile.h
 *
 *  Created on: 14 juil. 2013
 *      Author: picque_j
 */

#ifndef TILE_H_
#define TILE_H_

#include <string>
#include <map>
#include "../utils/NonCopyable.hpp"
#include "IProperty.hpp"

namespace Tiled
{

    class Tile: private NonCopyable
    {
    public:
	Tile() :
		_gid(0), _width(0), _height(0), _x(0), _y(0), _tilesetId(0), _tilesetX(0), _tilesetY(0)
	{

	}

	virtual ~Tile()
	{

	}

	int getGid() const
	{
	    return _gid;
	}

	void setGid(int gid)
	{
	    _gid = gid;
	}

	int getTilesetId() const
	{
	    return _tilesetId;
	}

	void setTilesetId(int tilesetId)
	{
	    _tilesetId = tilesetId;
	}

	int getTilesetX() const
	{
	    return _tilesetX;
	}

	void setTilesetX(int tilesetX)
	{
	    _tilesetX = tilesetX;
	}

	int getTilesetY() const
	{
	    return _tilesetY;
	}

	void setTilesetY(int tilesetY)
	{
	    _tilesetY = tilesetY;
	}

	int getX() const
	{
	    return _x;
	}

	void setX(int x)
	{
	    _x = x;
	}

	int getY() const
	{
	    return _y;
	}

	void setY(int y)
	{
	    _y = y;
	}

	int getHeight() const
	{
	    return _height;
	}

	void setHeight(int height)
	{
	    _height = height;
	}

	int getWidth() const
	{
	    return _width;
	}

	void setWidth(int width)
	{
	    _width = width;
	}
    private:
	int _gid;
	int _width;
	int _height;
	int _x;
	int _y;
	int _tilesetId;
	int _tilesetX;
	int _tilesetY;
    };

}
#endif /* TILE_H_ */
