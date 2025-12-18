/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:52:23 by njooris           #+#    #+#             */
/*   Updated: 2025/12/17 14:49:45 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_fractional = 8;

float	ft_pow(int base, float exp)
{
	float	ret = 1;
	for (int i = 0; i < exp; i++)
		ret *= base;
	return (ret);
}

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
	this->_fixed_point = static_cast <int>(floating_point * ft_pow(2, _fractional));
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
	std::cout << "getRawBits member function called1" << std::endl;
	return (_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "getRawBits member function called2" << std::endl;
	this->_fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	
	return (static_cast<float>(getRawBits()) / ft_pow(2, _fractional));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() / static_cast<int>(ft_pow(2, _fractional)));
}
