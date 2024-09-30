#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	
	std::cout << "max(a, b) is " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b) is " << Fixed::min(a, b) << std::endl;
	Fixed c(5);
	Fixed d(5);
	Fixed& test = Fixed::max(c, d);
	std::cout << &test << std::endl;
	std::cout << &c << std::endl;
	std::cout << &d << std::endl;
	std::cout << "max(c, d) is " << Fixed::max(c, d) << std::endl;
	
	std::cout << "a + b is " << a + b << std::endl;
	std::cout << "a - b is " << a - b << std::endl;
	std::cout << "a * b is " << a * b << std::endl;
	std::cout << "a / b is " << a / b << std::endl;
	
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl; 
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "--a is " << --a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a-- is " << a-- << std::endl;
	std::cout << "a is " << a << std::endl;
}
