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
	bool operator>(const Fixed&) const;
	bool operator<(const Fixed&) const;
	bool operator==(const Fixed&) const;
	bool operator!=(const Fixed&) const;
	bool operator>=(const Fixed&) const;
	bool operator<=(const Fixed&) const;
	Fixed operator+(const Fixed&) const;
	Fixed operator-(const Fixed&) const;
	Fixed operator*(const Fixed&) const;
	Fixed operator/(const Fixed&) const;
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	static Fixed& max(Fixed&, Fixed&);
	static const Fixed& max(const Fixed&, const Fixed&);
	static Fixed& min(Fixed&, Fixed&);
	static const Fixed& min(const Fixed&, const Fixed&);
};
std::ostream &operator<<(std::ostream&, const Fixed&);


#endif