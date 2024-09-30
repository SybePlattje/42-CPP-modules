#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int fixedPointValue;
	static const int fractionalBit = 8;
public:
	Fixed();
	Fixed( const int);
	Fixed( const float);
	Fixed( const Fixed &fixed);
	~Fixed();
	Fixed &operator = (const Fixed&);
	int getRawBits() const;
	void setRawBits(int const);
	float toFloat() const;
	int toInt() const;
};
std::ostream &operator<<(std::ostream&, const Fixed&);


#endif