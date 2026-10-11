#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- FragTrap construction/destruction order ---" << std::endl;
	{
		FragTrap	frag("Fraggy");
	}

	std::cout << "--- FragTrap actions ---" << std::endl;
	FragTrap	frag("Fragster");
	frag.attack("Bandit");
	frag.takeDamage(60);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "--- copy and assignment ---" << std::endl;
	FragTrap	copy(frag);
	FragTrap	assigned;
	assigned = frag;
	assigned.highFivesGuys();

	std::cout << "--- ScavTrap still works ---" << std::endl;
	ScavTrap	scav("Scavvy");
	scav.attack("Bandit");
	scav.guardGate();

	std::cout << "--- polymorphic delete ---" << std::endl;
	ClapTrap	*p = new FragTrap("Heap");
	p->attack("Target");
	delete p;

	std::cout << "--- killed FragTrap ---" << std::endl;
	frag.takeDamage(1000);
	frag.attack("Ghost");
	frag.highFivesGuys();

	std::cout << "--- destruction ---" << std::endl;
	return 0;
}
