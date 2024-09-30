#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int fixedPointValue;
	static const int fractionalBit = 8;
public:
	Fixed();
	Fixed( const Fixed &fixed);
	~Fixed();
	Fixed &operator = (const Fixed &a);
	int getRawBits() const;
	void setRawBits(int const);
};

#endif