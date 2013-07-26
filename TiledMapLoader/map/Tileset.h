/*
 * Tileset.h
 *
 *  Created on: 14 juil. 2013
 *      Author: picque_j
 */

#ifndef TILESET_H_
#define TILESET_H_

#include <string>
#include <map>
#include "../utils/NonCopyable.hpp"
#include "IProperty.hpp"

namespace Tiled
{

    class Tileset: public IProperty, private NonCopyable
    {
    public:
	Tileset() :
		_id(0), _firstGid(0), _width(0), _height(0), _tileWidth(0), _tileHeight(0), _spacing(0), _margin(0), _offsetX(0), _offsetY(0)
	{

	}

	virtual ~Tileset()
	{

	}

	unsigned getFirstGid() const
	{
	    return _firstGid;
	}

	void setFirstGid(unsigned firstGid)
	{
	    _firstGid = firstGid;
	}

	int getHeight() const
	{
	    return _height;
	}

	void setHeight(int height)
	{
	    _height = height;
	}

	int getId() const
	{
	    return _id;
	}

	void setId(int id)
	{
	    _id = id;
	}

	std::string getImageSource() const
	{
	    return _imageSource;
	}

	void setImageSource(std::string imageSource)
	{
	    _imageSource = imageSource;
	}

	int getMargin() const
	{
	    return _margin;
	}

	void setMargin(int margin)
	{
	    _margin = margin;
	}

	std::string getName() const
	{
	    return _name;
	}

	void setName(std::string name)
	{
	    _name = name;
	}

	void addProperty(const std::string &name, const std::string &value)
	{
	    _properties[name] = value;
	}

	std::map<std::string, std::string> getProperties() const
	{
	    return _properties;
	}

	void setProperties(std::map<std::string, std::string> properties)
	{
	    _properties = properties;
	}

	int getSpacing() const
	{
	    return _spacing;
	}

	void setSpacing(int spacing)
	{
	    _spacing = spacing;
	}

	int getTileHeight() const
	{
	    return _tileHeight;
	}

	void setTileHeight(int tileHeight)
	{
	    _tileHeight = tileHeight;
	}

	int getTileWidth() const
	{
	    return _tileWidth;
	}

	void setTileWidth(int tileWidth)
	{
	    _tileWidth = tileWidth;
	}

	int getWidth() const
	{
	    return _width;
	}

	void setWidth(int width)
	{
	    _width = width;
	}

	void addTileProperties(int tileId, const std::string &name, const std::string &value)
	{
	    _tileProperties[tileId][name] = value;
	}

	std::map<int, std::map<std::string, std::string> > getTileProperties() const
	{
	    return _tileProperties;
	}

	void setTileProperties(std::map<int, std::map<std::string, std::string> > tileProperties)
	{
	    _tileProperties = tileProperties;
	}

	int getOffsetX() const
	{
	    return _offsetX;
	}

	void setOffsetX(int offsetX)
	{
	    _offsetX = offsetX;
	}

	int getOffsetY() const
	{
	    return _offsetY;
	}

	void setOffsetY(int offsetY)
	{
	    _offsetY = offsetY;
	}
    private:
	std::map<int, std::map<std::string, std::string> > _tileProperties;
	std::map<std::string, std::string> _properties;
	std::string _name;
	std::string _imageSource;
	int _id;
	unsigned _firstGid;
	int _width;
	int _height;
	int _tileWidth;
	int _tileHeight;
	int _spacing;
	int _margin;
	int _offsetX;
	int _offsetY;
    };

}
#endif /* TILESET_H_ */
