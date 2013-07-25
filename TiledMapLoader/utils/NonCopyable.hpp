/*
 * NonCopyable.hpp
 *
 *  Created on: 11 juil. 2013
 *      Author: picque_j
 */

#ifndef NONCOPYABLE_HPP_
#define NONCOPYABLE_HPP_

class NonCopyable
{
public:
	NonCopyable() {};
	~NonCopyable() {};
private:
	NonCopyable(const NonCopyable &);
	NonCopyable &operator=(const NonCopyable &);
};

#endif /* NONCOPYABLE_HPP_ */
