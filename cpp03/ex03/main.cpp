#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- construction ---" << std::endl;
	DiamondTrap	d("Gem");

	std::cout << "--- whoAmI ---" << std::endl;
	d.whoAmI();

	std::cout << "--- attack (ScavTrap) and stats ---" << std::endl;
	d.attack("Skag");
	d.takeDamage(30);
	d.beRepaired(10);

	std::cout << "--- inherited special abilities ---" << std::endl;
	d.guardGate();
	d.highFivesGuys();

	std::cout << "--- copy ---" << std::endl;
	DiamondTrap	copy(d);
	copy.whoAmI();

	std::cout << "--- assignment ---" << std::endl;
	DiamondTrap	other("Other");
	other = d;
	other.whoAmI();

	std::cout << "--- polymorphic delete ---" << std::endl;
	ClapTrap	*p = new DiamondTrap("Heap");
	p->attack("Bandit");
	delete p;

	std::cout << "--- destruction ---" << std::endl;
	return 0;
}
