/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:52:23 by njooris           #+#    #+#             */
/*   Updated: 2026/01/05 14:50:23 by njooris          ###   ########.fr       */
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
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int fixed_point)
{
	this->_fixed_point = fixed_point << _fractional;
}

Fixed::Fixed(const float floating_point)
{
	this->_fixed_point = static_cast <int>(floating_point * ft_pow(2, _fractional));
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_fixed_point = fixed._fixed_point;
	return (*this);
}

Fixed&	Fixed::operator+(const Fixed &fixed)
{
	this->_fixed_point += fixed._fixed_point;
	return (*this); 
}

Fixed&	Fixed::operator-(const Fixed &fixed)
{
	this->_fixed_point -= fixed._fixed_point;
	return (*this);
}

Fixed&	Fixed::operator*(const Fixed &fixed)
{
	this->_fixed_point = (this->_fixed_point * fixed._fixed_point) / ft_pow(2, _fractional);
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed &fixed)
{
	this->_fixed_point = (this->_fixed_point / fixed._fixed_point) * ft_pow(2, _fractional);
	return (*this);
}

Fixed&	Fixed::operator++()
{
	_fixed_point++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	fixed = *this;
	_fixed_point++;
	return (fixed);
}

Fixed&	Fixed::operator--()
{
	_fixed_point--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	fixed = *this;
	_fixed_point++;
	return (fixed);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (_fixed_point < fixed.getRawBits());		
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (!(*this < fixed));
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (_fixed_point == fixed._fixed_point);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (!(*this == fixed));
}

std::ostream& 	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat() ;
	return (os);
}

int Fixed::getRawBits(void) const
{
	return (_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
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

const Fixed&	Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed&	Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed&	Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed&	Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}