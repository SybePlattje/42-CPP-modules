#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructer called"<< std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed( const Fixed &fixed)
{
	std::cout << "Copy constructer called"<< std::endl;
	this->fixedPointValue = fixed.fixedPointValue;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructer called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
		this->fixedPointValue = copy.fixedPointValue;
	std::cout << "Copy assignment operator called"<< std::endl;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedPointValue = raw;
}
