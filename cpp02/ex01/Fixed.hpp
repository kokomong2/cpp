#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& src);
		~Fixed();
		int toInt(void) const;
		float toFloat(void) const;
		Fixed&	operator=(const Fixed& src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif