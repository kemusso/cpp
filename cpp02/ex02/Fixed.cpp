#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n * (1 << _fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(static_cast<int>(roundf(f * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const
{
	return _value / (1 << _fractionalBits);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return _value > rhs._value;
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return _value < rhs._value;
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return _value >= rhs._value;
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return _value <= rhs._value;
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return _value == rhs._value;
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return _value != rhs._value;
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(_value + rhs._value);
	return result;
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(_value - rhs._value);
	return result;
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(static_cast<int>(
			(static_cast<long>(_value) * rhs._value) / (1 << _fractionalBits)));
	return result;
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(static_cast<int>(
			(static_cast<long>(_value) * (1 << _fractionalBits)) / rhs._value));
	return result;
}

Fixed	&Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	_value++;
	return old;
}

Fixed	&Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	_value--;
	return old;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
