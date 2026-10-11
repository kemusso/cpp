#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	static const unsigned int	_defaultHitPoints = 100;
	static const unsigned int	_defaultEnergyPoints = 100;
	static const unsigned int	_defaultAttackDamage = 30;

public:
	FragTrap(void);
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap	&operator=(const FragTrap &other);
	virtual ~FragTrap(void);

	void	highFivesGuys(void);
};

#endif
