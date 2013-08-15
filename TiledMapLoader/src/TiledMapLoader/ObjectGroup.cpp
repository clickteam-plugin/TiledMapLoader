#include <TiledMapLoader/ObjectGroup.h>

namespace TiledMapLoader
{

	const std::string &ObjectGroup::getDrawOrder() const
	{
		return mDrawOrder;
	}

	void ObjectGroup::setDrawOrder(const std::string &drawOrder)
	{
		mDrawOrder = drawOrder;
	}

	int ObjectGroup::getHeight() const
	{
		return mHeight;
	}

	void ObjectGroup::setHeight(int height)
	{
		mHeight = height;
	}

	const std::string &ObjectGroup::getName() const
	{
		return mName;
	}

	void ObjectGroup::setName(const std::string &name)
	{
		mName = name;
	}

	const std::vector<Object::Ptr> &ObjectGroup::getObjects() const
	{
		return mObjects;
	}

	void ObjectGroup::addObject(Object::Ptr object)
	{
		mObjects.push_back(std::move(object));
	}

	float ObjectGroup::getOpacity() const
	{
		return mOpacity;
	}

	void ObjectGroup::setOpacity(float opactity)
	{
		mOpacity = opactity;
	}

	int ObjectGroup::getVisible() const
	{
		return mVisible;
	}

	void ObjectGroup::setVisible(int visible)
	{
		mVisible = visible;
	}

	int ObjectGroup::getWidth() const
	{
		return mWidth;
	}

	void ObjectGroup::setWidth(int width)
	{
		mWidth = width;
	}

}
