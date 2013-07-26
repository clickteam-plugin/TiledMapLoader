/*
 * Object.h
 *
 *  Created on: 16 juil. 2013
 *      Author: picque_j
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <map>
#include "../utils/NonCopyable.hpp"
#include "IProperty.hpp"

namespace Tiled
{

    const unsigned FLIPPED_HORIZONTALLY_FLAG = 0x80000000;
    const unsigned FLIPPED_VERTICALLY_FLAG = 0x40000000;
    const unsigned FLIPPED_DIAGONALLY_FLAG = 0x20000000;

    class Object: public IProperty, private NonCopyable
    {
    public:
	Object() :
		_name(""), _type(""), _polygonType("object"), _vertices(""), _gid(0), _x(0), _y(0), _width(0), _height(0), _visible(1), _flippedHorizontally(0), _flippedVertically(0), _flippedDiagonally(0), _rotation(0)
	{

	}

	virtual ~Object()
	{

	}

	std::map<std::string, std::string> getProperties() const
	{
	    return _properties;
	}

	void addProperty(const std::string &name, const std::string &value)
	{
	    _properties[name] = value;
	}

	void setProperties(std::map<std::string, std::string> properties)
	{
	    _properties = properties;
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

	float getRotation() const
	{
	    return _rotation;
	}

	void setRotation(float rotation)
	{
	    _rotation = rotation;
	}

	std::string getType() const
	{
	    return _type;
	}

	void setType(std::string type)
	{
	    _type = type;
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

	unsigned getGid() const
	{
	    return _gid;
	}

	void setGid(unsigned gid)
	{
	    _gid = gid & ~(FLIPPED_HORIZONTALLY_FLAG | FLIPPED_VERTICALLY_FLAG | FLIPPED_DIAGONALLY_FLAG);
	    _flippedHorizontally = gid & FLIPPED_HORIZONTALLY_FLAG;
	    _flippedVertically = gid & FLIPPED_VERTICALLY_FLAG;
	    _flippedDiagonally = gid & FLIPPED_DIAGONALLY_FLAG;
	}

	std::string getVertices() const
	{
	    return _vertices;
	}

	void setVertices(std::string vertices)
	{
	    _vertices = vertices;
	}

	std::string getPolygonType() const
	{
	    return _polygonType;
	}

	void setPolygonType(std::string polygonType)
	{
	    _polygonType = polygonType;
	}

	int isFlippedHorizontally() const
	{
	    return _flippedHorizontally;
	}

	int isFlippedVertically() const
	{
	    return _flippedVertically;
	}

	int isFlippedDiagonally() const
	{
	    return _flippedDiagonally;
	}
    private:
	std::map<std::string, std::string> _properties;
	std::string _name;
	std::string _type;
	std::string _polygonType;
	std::string _vertices;
	unsigned _gid;
	int _x;
	int _y;
	int _width;
	int _height;
	int _visible;
	int _flippedHorizontally;
	int _flippedVertically;
	int _flippedDiagonally;
	float _rotation;
    };

}
#endif /* OBJECT_H_ */
