/*
 * Map.h
 *
 *  Created on: 14 juil. 2013
 *      Author: picque_j
 */

#ifndef MAP_H_
#define MAP_H_

#include <string>
#include <map>
#include <vector>
#include "../utils/NonCopyable.hpp"
#include "IProperty.hpp"
#include "Tileset.h"
#include "Layer.h"
#include "ObjectGroup.h"

namespace Tiled
{

    class Map: public IProperty, private NonCopyable
    {
    public:
	Map() :
		_version("1.0"), _orientation("orthogonal"), _width(0), _height(0), _tileWidth(0), _tileHeight(0)
	{

	}

	virtual ~Map()
	{
	    for (std::vector<Tileset *>::iterator it = _tilesets.begin(); it != _tilesets.end(); ++it)
		delete *it;
	    for (std::vector<Layer *>::iterator it = _layers.begin(); it != _layers.end(); ++it)
		delete *it;
	    for (std::vector<ObjectGroup *>::iterator it = _objectGroups.begin(); it != _objectGroups.end(); ++it)
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

	std::string getOrientation() const
	{
	    return _orientation;
	}

	void setOrientation(std::string orientation)
	{
	    _orientation = orientation;
	}

	std::string getVersion() const
	{
	    return _version;
	}

	void setVersion(std::string version)
	{
	    _version = version;
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

	void addLayer(Layer *layer)
	{
	    _layers.push_back(layer);
	}

	std::vector<Layer *> getLayers() const
	{
	    return _layers;
	}

	void setLayers(std::vector<Layer *> layers)
	{
	    _layers = layers;
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

	void addTileset(Tileset *tileset)
	{
	    _tilesets.push_back(tileset);
	}

	std::vector<Tileset *> getTilesets() const
	{
	    return _tilesets;
	}

	void setTilesets(std::vector<Tileset *> tilesets)
	{
	    _tilesets = tilesets;
	}

	void addObjectGroup(ObjectGroup *objectGroup)
	{
	    _objectGroups.push_back(objectGroup);
	}

	std::vector<ObjectGroup*> getObjectGroups() const
	{
	    return _objectGroups;
	}

	void setObjectGroups(std::vector<ObjectGroup*> objectGroups)
	{
	    _objectGroups = objectGroups;
	}
    private:
	std::map<std::string, std::string> _properties;
	std::vector<Tileset *> _tilesets;
	std::vector<Layer *> _layers;
	std::vector<ObjectGroup *> _objectGroups;
	std::string _version;
	std::string _orientation;
	int _width;
	int _height;
	int _tileWidth;
	int _tileHeight;
    };

}
#endif /* MAP_H_ */
