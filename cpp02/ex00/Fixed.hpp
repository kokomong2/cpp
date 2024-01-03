#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& src);
		~Fixed();
		Fixed&	operator=(const Fixed& src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif