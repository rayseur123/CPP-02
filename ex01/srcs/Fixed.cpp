/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:52:23 by njooris           #+#    #+#             */
/*   Updated: 2026/01/07 11:50:21 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractional = 8;

Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int fixed_point)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = fixed_point << _fractional;
}

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(floating_point * (float)(1 << _fractional));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_fixed_point = fixed._fixed_point;
	return (*this);
}

std::ostream& 	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat() ;
	return (os);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "getRawBits member function called" << std::endl;
	this->_fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	return (_fixed_point / (float)(1 << _fractional));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _fractional);
}
