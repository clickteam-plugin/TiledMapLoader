#include <TiledMapLoader/Object.h>

const unsigned FLIPPED_HORIZONTALLY_FLAG = 0x80000000;
const unsigned FLIPPED_VERTICALLY_FLAG = 0x40000000;
const unsigned FLIPPED_DIAGONALLY_FLAG = 0x20000000;

namespace TiledMapLoader
{

	unsigned Object::getGid() const
	{
		return mGid;
	}

	void Object::setGid(unsigned gid)
	{
		mGid = gid & ~(FLIPPED_HORIZONTALLY_FLAG | FLIPPED_VERTICALLY_FLAG | FLIPPED_DIAGONALLY_FLAG);
		mFlippedHorizontally = gid & FLIPPED_HORIZONTALLY_FLAG;
		mFlippedVertically = gid & FLIPPED_VERTICALLY_FLAG;
		mFlippedDiagonally = gid & FLIPPED_DIAGONALLY_FLAG;
	}

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

	int Object::getHeight() const
	{
		return (int) mHeight;
	}

	void Object::setHeight(int height)
	{
		mHeight = (float) height;
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

	float Object::getWidth() const
	{
		return mWidth;
	}

	void Object::setWidth(float width)
	{
		mWidth = width;
	}

	float Object::getX() const
	{
		return mX;
	}

	void Object::setX(float x)
	{
		mX = x;
	}

	float Object::getY() const
	{
		return mY;
	}

	void Object::setY(float y)
	{
		mY = y;
	}

}
