#pragma once

#include <sstream>
#include <string>

#include "../lib/rapidxml/rapidxml.hpp"

namespace TiledMapLoader {

	class XMLElement {
	public:
		explicit XMLElement(rapidxml::xml_node<> &node);

	public:
		int getInt(const char *name, int defaultValue = 0) const;
		unsigned getUnsignedInt(const char *name, unsigned defaultValue = 0) const;
		float getFloat(const char *name, float defaultValue = 0) const;
		char *getString(const char *name, char *defaultValue = static_cast<char *>("")) const;
		char *getValue(char *defaultValue = nullptr) const;

	private:
		rapidxml::xml_node<> &mNode;
	};

}
