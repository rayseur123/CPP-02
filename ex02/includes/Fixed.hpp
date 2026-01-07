/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:28:33 by njooris           #+#    #+#             */
/*   Updated: 2026/01/07 15:44:20 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixed_point;
		static const int	_fractional;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int fixed_point);
		Fixed(const float floating_point);
		~Fixed();
		
		Fixed	&operator=(const Fixed &fixed);
		Fixed	operator+(const Fixed &fixed);
		Fixed	operator-(const Fixed &fixed);
		Fixed	operator*(const Fixed &fixed);
		Fixed	operator/(const Fixed &fixed);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		
		bool	operator<(const Fixed &fixed) const;
		bool	operator>(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float 	toFloat(void) const;
		int		toInt(void) const;
		
		const static Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		const static Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);

};	

std::ostream&	operator<<(std::ostream&os, const Fixed&fixed);

#endif