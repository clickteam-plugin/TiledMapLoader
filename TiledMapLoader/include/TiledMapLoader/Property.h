#pragma once

#include <map>
#include <string>

#include "../lib/rapidxml/rapidxml.hpp"

namespace TiledMapLoader
{

	class Property
	{
	public:
		typedef std::map<std::string, std::string> Properties;

	public:
		void addProperty(const std::string &key, const std::string &value);
		std::string getProperty(const std::string &key) const;

	public:
		const Properties &getProperties() const;
		void setProperties(const Properties &properties);

	public:
		void parseProperties(rapidxml::xml_node<> &node);

	protected:
		Properties mProperties;
	};

}
