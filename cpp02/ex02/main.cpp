#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "---- extra tests ----" << std::endl;
	Fixed	x(3.5f);
	Fixed	y(-2);

	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x > y: " << (x > y) << std::endl;
	std::cout << "x < y: " << (x < y) << std::endl;
	std::cout << "x >= x: " << (x >= x) << std::endl;
	std::cout << "x <= y: " << (x <= y) << std::endl;
	std::cout << "x == x: " << (x == x) << std::endl;
	std::cout << "x != y: " << (x != y) << std::endl;
	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;
	std::cout << "--x = " << --x << std::endl;
	std::cout << "x-- = " << x-- << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;
	std::cout << "min(const) = " << Fixed::min(Fixed(1), Fixed(2)) << std::endl;
	return 0;
}
