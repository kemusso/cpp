#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
	: ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), _name("default")
{
	_hitPoints = FragTrap::_defaultHitPoints;
	_energyPoints = ScavTrap::_defaultEnergyPoints;
	_attackDamage = FragTrap::_defaultAttackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_defaultHitPoints;
	_energyPoints = ScavTrap::_defaultEnergyPoints;
	_attackDamage = FragTrap::_defaultAttackDamage;
	std::cout << "DiamondTrap " << _name << " is forged" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " is shattered" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << ", and my ClapTrap name is "
		<< ClapTrap::_name << std::endl;
}
