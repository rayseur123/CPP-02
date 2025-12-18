/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:03:02 by njooris           #+#    #+#             */
/*   Updated: 2025/12/18 11:25:04 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

Fixed	sign(Point const &a, Point const &b, Point const &c)
{
	return (a.get_x() - c.get_x()) * (b.get_y() - c.get_y())
	     - (b.get_x() - c.get_x()) * (a.get_y() - c.get_y());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float 	d1;
	float 	d2;
	float 	d3;
	bool	has_neg;
	bool	has_pos;

	d1 = sign(point, a, b).toFloat();
	d2 = sign(point, b, c).toFloat();
	d3 = sign(point, c, a).toFloat();
	
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return (!(has_neg && has_pos));
}

int main( void )
{
	Point	a(-0.5, -0.5);
	Point	b(0.5, -0.5);
	Point	c(0.5, 0.5);
	Point	point(0, 0);

	if (bsp(a, b , c, point))
		std::cout << "yes" << std::endl;
	else
		std::cout << "nop" << std::endl;

	Point	d(-0.5, -0.5);
	Point	e(0.5, -0.5);
	Point	f(0.5, 0.5);
	Point	point2(0.5, 0.5);

	if (bsp(d, e , f, point2))
		std::cout << "yes" << std::endl;
	else
		std::cout << "nop" << std::endl;
		
	Point	g(-0.5, -0.5);
	Point	h(0.5, -0.5);
	Point	i(0.5, 0.5);
	Point	point3(0.5, 0.6);

	if (bsp(g, h , i, point3))
		std::cout << "yes" << std::endl;
	else
		std::cout << "nop" << std::endl; 

	return 0;
}