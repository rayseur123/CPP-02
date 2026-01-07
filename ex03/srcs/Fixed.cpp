/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:52:23 by njooris           #+#    #+#             */
/*   Updated: 2026/01/07 11:56:23 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractional = 8;

Fixed::Fixed() : _fixed_point(0)
{
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int fixed_point)
{
	this->_fixed_point = fixed_point * (float)(1 << _fractional);
}

Fixed::Fixed(const float floating_point)
{
	this->_fixed_point = roundf(floating_point * (float)(1 << _fractional));
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
	this->_fixed_point = (this->_fixed_point * fixed._fixed_point) / (float)(1 << _fractional);
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed &fixed)
{
	this->_fixed_point = (this->_fixed_point / fixed._fixed_point) * (float)(1 << _fractional);
	return (*this);
}

Fixed	&Fixed::operator++()
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

Fixed	&Fixed::operator--()
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
	return (getRawBits()) / (float)(1 << _fractional);
}

int	Fixed::toInt(void) const
{
	return (getRawBits() / (float)(1 << _fractional));
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}