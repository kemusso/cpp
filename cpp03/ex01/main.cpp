#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- ClapTrap ---" << std::endl;
	{
		ClapTrap	clap("Clappy");
		clap.attack("Skag");
	}

	std::cout << "--- ScavTrap construction/destruction order ---" << std::endl;
	{
		ScavTrap	scav("Serena");
	}

	std::cout << "--- ScavTrap actions ---" << std::endl;
	ScavTrap	scav("Scavvy");
	scav.attack("Bandit");
	scav.takeDamage(42);
	scav.beRepaired(12);
	scav.guardGate();

	std::cout << "--- copy and assignment ---" << std::endl;
	ScavTrap	copy(scav);
	ScavTrap	assigned;
	assigned = scav;
	copy.attack("Copycat");

	std::cout << "--- polymorphic delete ---" << std::endl;
	ClapTrap	*p = new ScavTrap("Heap");
	p->attack("Target");
	delete p;

	std::cout << "--- energy exhaustion (50 energy) ---" << std::endl;
	ScavTrap	tired("Tired");
	for (int i = 0; i < 50; i++)
		tired.attack("Dummy");
	tired.attack("Dummy");

	std::cout << "--- destruction ---" << std::endl;
	return 0;
}
