#pragma once

#include <memory>
#include <vector>
#include <string>

#include <TiledMapLoader/Tile.h>
#include <TiledMapLoader/Property.h>

namespace TiledMapLoader {

	class Layer : public Property {
	public:
		using Ptr = std::unique_ptr<Layer>;
		using Tiles = std::vector<Tile::Ptr>;

	public:
		int getHeight() const;
		void setHeight(int height);
		const std::string &getName() const;
		void setName(const std::string &name);
		float getOpacity() const;
		void setOpacity(float opacity);
		int getVisible() const;
		void setVisible(int visible);
		int getWidth() const;
		void setWidth(int width);
		int getId() const;
		void setId(int id);
		const Tiles &getTiles() const;
		void addTile(Tile::Ptr tile);

	private:
		Tiles mTiles;
		std::string mName;
		int mId;
		int mWidth;
		int mHeight;
		float mOpacity;
		int mVisible;
	};

}
