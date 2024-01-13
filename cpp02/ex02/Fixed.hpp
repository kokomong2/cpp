#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& src);
		~Fixed();
		int toInt(void) const;
		float toFloat(void) const;
		Fixed&	operator=(const Fixed& src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&		operator++(void);
		const Fixed	operator++(int);
		Fixed&		operator--(void);
		const Fixed	operator--(int);
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& src);
bool		operator>(const Fixed& lhs, const Fixed& rhs);
bool		operator<(const Fixed& lhs, const Fixed& rhs);
bool		operator>=(const Fixed& lhs, const Fixed& rhs);
bool		operator<=(const Fixed& lhs, const Fixed& rhs);
bool		operator==(const Fixed& lhs, const Fixed& rhs);
bool		operator!=(const Fixed& lhs, const Fixed& rhs);
Fixed		operator+(const Fixed& lhs, const Fixed& rhs);
Fixed		operator-(const Fixed& lhs, const Fixed& rhs);
Fixed		operator*(const Fixed& lhs, const Fixed& rhs);
Fixed		operator/(const Fixed& lhs, const Fixed& rhs);

#endif