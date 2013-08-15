#pragma once

#include <memory>
#include <string>

#include <TiledMapLoader/Property.h>

namespace TiledMapLoader
{

	const unsigned FLIPPED_HORIZONTALLY_FLAG = 0x80000000;
	const unsigned FLIPPED_VERTICALLY_FLAG = 0x40000000;
	const unsigned FLIPPED_DIAGONALLY_FLAG = 0x20000000;

	class Object: public Property
	{
	public:
		typedef std::unique_ptr<Object> Ptr;

		int getFlippedDiagonally() const;
		void setFlippedDiagonally(int flippedDiagonally);
		int getFlippedHorizontally() const;
		void setFlippedHorizontally(int flippedHorizontally);
		int getFlippedVertically() const;
		void setFlippedVertically(int flippedVertically);
		unsigned getGid() const;
		void setGid(unsigned gid);
		int getHeight() const;
		void setHeight(int height);
		const std::string& getName() const;
		void setName(const std::string& name);
		const std::string& getPolygonType() const;
		void setPolygonType(const std::string& polygonType);
		float getRotation() const;
		void setRotation(float rotation);
		const std::string& getType() const;
		void setType(const std::string& type);
		const std::string& getVertices() const;
		void setVertices(const std::string& vertices);
		int getVisible() const;
		void setVisible(int visible);
		int getWidth() const;
		void setWidth(int width);
		int getX() const;
		void setX(int x);
		int getY() const;
		void setY(int y);

	private:
		std::string mName;
		std::string mType;
		std::string mPolygonType;
		std::string mVertices;
		unsigned mGid;
		int mX;
		int mY;
		int mWidth;
		int mHeight;
		int mVisible;
		int mFlippedHorizontally;
		int mFlippedVertically;
		int mFlippedDiagonally;
		float mRotation;
	};

}
