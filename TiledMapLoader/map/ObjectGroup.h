/*
 * ObjectGroup.h
 *
 *  Created on: 16 juil. 2013
 *      Author: picque_j
 */

#ifndef OBJECTGROUP_H_
#define OBJECTGROUP_H_

#include <string>
#include <vector>
#include <map>
#include "../utils/NonCopyable.hpp"
#include "Object.h"

namespace Tiled
{

    class ObjectGroup: public IProperty, private NonCopyable
    {
    public:
	ObjectGroup() :
		_name(""), _drawOrder(""), _width(0), _height(0), _opacity(1), _visible(1)
	{

	}

	virtual ~ObjectGroup()
	{
	    for (std::vector<Object *>::iterator it = _objects.begin(); it != _objects.end(); ++it)
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

	void addObject(Object *object)
	{
	    _objects.push_back(object);
	}

	std::vector<Object*> getObjects() const
	{
	    return _objects;
	}

	void setObjects(std::vector<Object*> objects)
	{
	    _objects = objects;
	}

	std::map<std::string, std::string> getProperties() const
	{
	    return _properties;
	}

	void setProperties(std::map<std::string, std::string> properties)
	{
	    _properties = properties;
	}

	int getWidth() const
	{
	    return _width;
	}

	void setWidth(int width)
	{
	    _width = width;
	}

	void addProperty(const std::string &name, const std::string &value)
	{
	    _properties[name] = value;
	}

	std::string getDrawOrder() const
	{
	    return _drawOrder;
	}

	void setDrawOrder(std::string drawOrder)
	{
	    _drawOrder = drawOrder;
	}

	int isVisible() const
	{
	    return _visible;
	}

	void setVisible(int visible)
	{
	    _visible = visible;
	}

	float getOpacity() const
	{
	    return _opacity;
	}

	void setOpacity(float opacity)
	{
	    _opacity = opacity;
	}
    private:
	std::map<std::string, std::string> _properties;
	std::vector<Object *> _objects;
	std::string _name;
	std::string _drawOrder;
	int _width;
	int _height;
	float _opacity;
	int _visible;
    };

}

#endif /* OBJECTGROUP_H_ */
