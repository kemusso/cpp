#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
	static const unsigned int	_defaultHitPoints = 100;
	static const unsigned int	_defaultEnergyPoints = 50;
	static const unsigned int	_defaultAttackDamage = 20;

public:
	ScavTrap(void);
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap	&operator=(const ScavTrap &other);
	virtual ~ScavTrap(void);

	virtual void	attack(const std::string &target);
	void			guardGate(void);
};

#endif
