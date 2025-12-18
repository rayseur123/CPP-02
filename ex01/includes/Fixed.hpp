/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:28:33 by njooris           #+#    #+#             */
/*   Updated: 2025/12/16 14:28:22 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		
		Fixed&			operator=(const Fixed &fixed);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float 	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& 	operator<<(std::ostream& os, const Fixed& fixed);

