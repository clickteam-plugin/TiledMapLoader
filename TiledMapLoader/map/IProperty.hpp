/*
 * IProperty.hpp
 *
 *  Created on: 15 juil. 2013
 *      Author: picque_j
 */

#ifndef IPROPERTY_HPP_
#define IPROPERTY_HPP_

#include <string>

namespace Tiled
{

    class IProperty
    {
    public:
	virtual ~IProperty() {}

	virtual void addProperty(const std::string &, const std::string &) = 0;
    };

}

#endif /* IPROPERTY_HPP_ */
