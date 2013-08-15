#include <TiledMapLoader/Object.h>

namespace TiledMapLoader
{

	int Object::getFlippedDiagonally() const
	{
		return mFlippedDiagonally;
	}

	void Object::setFlippedDiagonally(int flippedDiagonally)
	{
		mFlippedDiagonally = flippedDiagonally;
	}

	int Object::getFlippedHorizontally() const
	{
		return mFlippedHorizontally;
	}

	void Object::setFlippedHorizontally(int flippedHorizontally)
	{
		mFlippedHorizontally = flippedHorizontally;
	}

	int Object::getFlippedVertically() const
	{
		return mFlippedVertically;
	}

	void Object::setFlippedVertically(int flippedVertically)
	{
		mFlippedVertically = flippedVertically;
	}

	unsigned Object::getGid() const
	{
		return mGid;
	}

	void Object::setGid(unsigned gid)
	{
		mGid = gid;
		mFlippedHorizontally = gid & FLIPPED_HORIZONTALLY_FLAG;
		mFlippedVertically = gid & FLIPPED_VERTICALLY_FLAG;
		mFlippedDiagonally = gid & FLIPPED_DIAGONALLY_FLAG;
	}

	int Object::getHeight() const
	{
		return mHeight;
	}

	void Object::setHeight(int height)
	{
		mHeight = height;
	}

	const std::string& Object::getName() const
	{
		return mName;
	}

	void Object::setName(const std::string& name)
	{
		mName = name;
	}

	const std::string& Object::getPolygonType() const
	{
		return mPolygonType;
	}

	void Object::setPolygonType(const std::string& polygonType)
	{
		mPolygonType = polygonType;
	}

	float Object::getRotation() const
	{
		return mRotation;
	}

	void Object::setRotation(float rotation)
	{
		mRotation = rotation;
	}

	const std::string& Object::getType() const
	{
		return mType;
	}

	void Object::setType(const std::string& type)
	{
		mType = type;
	}

	const std::string& Object::getVertices() const
	{
		return mVertices;
	}

	void Object::setVertices(const std::string& vertices)
	{
		mVertices = vertices;
	}

	int Object::getVisible() const
	{
		return mVisible;
	}

	void Object::setVisible(int visible)
	{
		mVisible = visible;
	}

	int Object::getWidth() const
	{
		return mWidth;
	}

	void Object::setWidth(int width)
	{
		mWidth = width;
	}

	int Object::getX() const
	{
		return mX;
	}

	void Object::setX(int x)
	{
		mX = x;
	}

	int Object::getY() const
	{
		return mY;
	}

	void Object::setY(int y)
	{
		mY = y;
	}

}
