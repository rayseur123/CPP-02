/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:00:20 by njooris           #+#    #+#             */
/*   Updated: 2025/12/17 17:54:27 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	public:
		Point();
		Point(float x, float y);
		Point(Point	&point);
		Fixed	get_x() const;
		Fixed	get_y() const;
		Point	&operator=(Point &point);
		~Point();
		
};

#endif