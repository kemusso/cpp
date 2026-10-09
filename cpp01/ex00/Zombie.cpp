#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
