#pragma once

#include <memory>
#include <vector>
#include <string>

#include <TiledMapLoader/Property.h>
#include <TiledMapLoader/Object.h>

namespace TiledMapLoader {

	class ObjectGroup: public Property {
	public:
		typedef std::unique_ptr<ObjectGroup> Ptr;
		typedef std::vector<Object::Ptr> Objects;

		const std::string &getDrawOrder() const;
		void setDrawOrder(const std::string &drawOrder);
		int getHeight() const;
		void setHeight(int height);
		const std::string &getName() const;
		void setName(const std::string &name);
		const Objects &getObjects() const;
		void addObject(Object::Ptr object);
		float getOpacity() const;
		void setOpacity(float opactity);
		int getVisible() const;
		void setVisible(int visible);
		int getWidth() const;
		void setWidth(int width);

	private:
		Objects mObjects;
		std::string mName;
		std::string mDrawOrder;
		int mWidth;
		int mHeight;
		float mOpacity;
		int mVisible;
	};

}
