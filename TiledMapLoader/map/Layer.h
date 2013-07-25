/*
 * Layer.h
 *
 *  Created on: 14 juil. 2013
 *      Author: picque_j
 */

#ifndef LAYER_H_
#define LAYER_H_

#include <string>
#include <map>
#include "../utils/NonCopyable.hpp"
#include "IProperty.hpp"
#include "Tile.h"

namespace Tiled
{

    class Layer: public IProperty, private NonCopyable
    {
    public:
	Layer() :
		_name(""), _width(0), _height(0), _opacity(1), _visible(1)
	{

	}

	virtual ~Layer()
	{
	    for (std::vector<Tile *>::iterator it = _tiles.begin(); it != _tiles.end(); ++it)
		delete *it;
	}

	int getHeight() const
	{
	    return _height;
	}

	void setHeight(int height)
	{
	    _height = height;
	}

	std::string getName() const
	{
	    return _name;
	}

	void setName(std::string name)
	{
	    _name = name;
	}

	float getOpacity() const
	{
	    return _opacity;
	}

	void setOpacity(float opacity)
	{
	    _opacity = opacity;
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

	void addTile(Tile *tile)
	{
	    _tiles.push_back(tile);
	}

	std::vector<Tile*> getTiles() const
	{
	    return _tiles;
	}

	void setTiles(std::vector<Tile*> tiles)
	{
	    _tiles = tiles;
	}

	int isVisible() const
	{
	    return _visible;
	}

	void setVisible(int visible)
	{
	    _visible = visible;
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
	std::map<std::string, std::string> _properties;
	std::vector<Tile *> _tiles;
	std::string _name;
	int _width;
	int _height;
	float _opacity;
	int _visible;
    };

}
#endif /* LAYER_H_ */
