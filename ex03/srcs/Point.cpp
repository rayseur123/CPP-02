/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:07:33 by njooris           #+#    #+#             */
/*   Updated: 2025/12/17 17:12:54 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point(float x, float y) : _x(x), _y(y)
{
	return ;
}

Point::Point(Point &point)
{
	this->_x = point._x;
	this->_y = point._y;
}

Point::~Point()
{
	return ;
}

Point	&Point::operator=(Point &point)
{
	this->_x = point._x;
	this->_y = point._y;
	return (*this);
}

Fixed	Point::get_x() const
{
	return (_x);	
}

Fixed	Point::get_y() const
{
	return (_y);	
}