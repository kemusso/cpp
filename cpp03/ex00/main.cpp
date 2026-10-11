#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- construction ---" << std::endl;
	ClapTrap	a("Clappy");
	ClapTrap	b(a);
	ClapTrap	c;

	c = a;

	std::cout << "--- basic actions ---" << std::endl;
	a.attack("Skag");
	a.takeDamage(3);
	a.beRepaired(2);

	std::cout << "--- energy exhaustion (10 energy) ---" << std::endl;
	for (int i = 0; i < 10; i++)
		b.attack("Dummy");
	b.attack("Dummy");
	b.beRepaired(5);

	std::cout << "--- no hit points left ---" << std::endl;
	c.takeDamage(100);
	c.takeDamage(1);
	c.attack("Ghost");
	c.beRepaired(5);

	std::cout << "--- destruction ---" << std::endl;
	return 0;
}
