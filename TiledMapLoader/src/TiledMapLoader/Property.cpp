#include <TiledMapLoader/Property.h>
#include <TiledMapLoader/XMLElement.h>

namespace TiledMapLoader {

	void Property::addProperty(const std::string &key, const std::string &value) {
		mProperties[key] = value;
	}

	std::string Property::getProperty(const std::string &key) const {
		std::string returnValue;
		auto found = mProperties.find(key);
		if (found != mProperties.end()) {
			returnValue = found->second;
		}
		return returnValue;
	}

	const std::map<std::string, std::string> &Property::getProperties() const {
		return mProperties;
	}

	void Property::setProperties(const std::map<std::string, std::string> &properties) {
		mProperties = properties;
	}

	void Property::parseProperties(rapidxml::xml_node<> &node) {
		rapidxml::xml_node<> *nodeProperties = nullptr;
		rapidxml::xml_node<> *nodeProperty = nullptr;
		nodeProperties = node.first_node("properties");
		if (nodeProperties) {
			nodeProperty = nodeProperties->first_node("property");
			while (nodeProperty) {
				XMLElement propertyNode(*nodeProperty);
				char *name = propertyNode.getString("name");
				char *value = propertyNode.getString("value");
				if (name && value) {
					addProperty(name, value);
				}
				nodeProperty = nodeProperty->next_sibling("property");
			}
		}
	}

}
