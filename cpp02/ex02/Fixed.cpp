#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = src.getRawBits();
	return (*this);
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return (os);
}

bool		operator>(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() > rhs.getRawBits());
}

bool		operator<(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() < rhs.getRawBits());
}

bool		operator>=(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() >= rhs.getRawBits());
}

bool		operator<=(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() <= rhs.getRawBits());
}

bool		operator==(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() == rhs.getRawBits());
}

bool		operator!=(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() != rhs.getRawBits());
}

Fixed		operator+(const Fixed& lhs, const Fixed& rhs)
{
	return (Fixed(lhs.toFloat() + rhs.toFloat()));
}

Fixed		operator-(const Fixed& lhs, const Fixed& rhs)
{
	return (Fixed(lhs.toFloat() - rhs.toFloat()));
}

Fixed		operator*(const Fixed& lhs, const Fixed& rhs)
{
	return (Fixed(lhs.toFloat() * rhs.toFloat()));
}

Fixed		operator/(const Fixed& lhs, const Fixed& rhs)
{
	return (Fixed(lhs.toFloat() / rhs.toFloat()));
}

Fixed&		Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

const Fixed		Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed&		Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

const Fixed		Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_value--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}

