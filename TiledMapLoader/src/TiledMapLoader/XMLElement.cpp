#include <TiledMapLoader/XMLElement.h>

namespace TiledMapLoader
{

	XMLElement::XMLElement(rapidxml::xml_node<>& node) :
			mNode(node)
	{
	}

	int XMLElement::getInt(const char *name, int defaultValue) const
	{
		rapidxml::xml_attribute<> *result = 0;
		char *value = 0;

		result = mNode.first_attribute(name);
		if (!result)
			return defaultValue;
		value = result->value();
		if (!value)
			return defaultValue;
		return atoi(value);
	}

	float XMLElement::getFloat(const char *name, float defaultValue) const
	{
		rapidxml::xml_attribute<> *result = 0;
		char *value = 0;

		result = mNode.first_attribute(name);
		if (!result)
			return defaultValue;
		value = result->value();
		if (!value)
			return defaultValue;
		return (float) atof(value);
	}

	char *XMLElement::getString(const char *name, char *defaultValue) const
	{
		rapidxml::xml_attribute<> *result = 0;
		char *value = 0;

		result = mNode.first_attribute(name);
		if (!result)
			return defaultValue;
		value = result->value();
		if (!value)
			return defaultValue;
		return value;
	}

}

char* TiledMapLoader::XMLElement::getValue(char* defaultValue) const
{
	char *value = mNode.value();

	return value ? value : defaultValue;
}
