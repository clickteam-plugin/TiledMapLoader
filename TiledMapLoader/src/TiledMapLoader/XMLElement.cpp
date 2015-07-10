#include <TiledMapLoader/XMLElement.h>

namespace TiledMapLoader {

	XMLElement::XMLElement(rapidxml::xml_node<> &node) :
		mNode(node) {

	}

	int XMLElement::getInt(const char *name, int defaultValue) const {
		rapidxml::xml_attribute<> *result = nullptr;
		char *value = nullptr;
		result = mNode.first_attribute(name);
		if (!result)
			return defaultValue;
		value = result->value();
		if (!value)
			return defaultValue;
		return std::stoi(value);
	}

	unsigned XMLElement::getUnsignedInt(const char *name, unsigned defaultValue) const {
		rapidxml::xml_attribute<> *result = nullptr;
		char *value = nullptr;
		result = mNode.first_attribute(name);
		if (!result)
			return defaultValue;
		value = result->value();
		if (!value)
			return defaultValue;
		return std::stoul(value);
	}

	float XMLElement::getFloat(const char *name, float defaultValue) const {
		rapidxml::xml_attribute<> *result = nullptr;
		char *value = nullptr;
		result = mNode.first_attribute(name);
		if (!result)
			return defaultValue;
		value = result->value();
		if (!value)
			return defaultValue;
		return std::stof(value);
	}

	char *XMLElement::getString(const char *name, char *defaultValue) const {
		rapidxml::xml_attribute<> *result = nullptr;
		char *value = nullptr;
		result = mNode.first_attribute(name);
		if (!result)
			return defaultValue;
		value = result->value();
		if (!value)
			return defaultValue;
		return value;
	}

}

char *TiledMapLoader::XMLElement::getValue(char *defaultValue) const {
	auto value = mNode.value();
	return value ? value : defaultValue;
}
