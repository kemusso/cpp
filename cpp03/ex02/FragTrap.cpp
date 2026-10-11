#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = _defaultHitPoints;
	_energyPoints = _defaultEnergyPoints;
	_attackDamage = _defaultAttackDamage;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = _defaultHitPoints;
	_energyPoints = _defaultEnergyPoints;
	_attackDamage = _defaultAttackDamage;
	std::cout << "FragTrap " << _name << " is assembled" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " is disassembled" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " raises a hand: high five, guys!" << std::endl;
}
