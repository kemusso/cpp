#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void	printInventory(const Character &c)
{
	std::cout << c.getName() << " inventory:";
	for (int i = 0; i < 4; i++)
	{
		const AMateria	*m = c.getMateria(i);

		std::cout << " [" << (m ? m->getType() : "empty") << "]";
	}
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << "--- subject test ---" << std::endl;
	{
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter	*me = new Character("me");

		AMateria	*tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter	*bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "--- unknown type and full source ---" << std::endl;
	{
		MateriaSource	src;

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		AMateria	*unknown = src.createMateria("fire");
		std::cout << "createMateria(\"fire\") returned "
			<< (unknown ? "a materia" : "0") << std::endl;
	}

	std::cout << "--- full inventory, invalid indexes ---" << std::endl;
	{
		MateriaSource	src;
		Character		alice("alice");
		Character		target("target");

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		for (int i = 0; i < 4; i++)
			alice.equip(src.createMateria(i % 2 ? "cure" : "ice"));
		printInventory(alice);
		AMateria	*extra = src.createMateria("ice");
		alice.equip(extra);
		printInventory(alice);
		delete extra;
		alice.equip(0);
		alice.use(-1, target);
		alice.use(4, target);
		alice.unequip(42);
		for (int i = 0; i < 4; i++)
			alice.use(i, target);
	}

	std::cout << "--- unequip leaves materia on the floor ---" << std::endl;
	{
		MateriaSource	src;
		Character		alice("alice");
		Character		target("target");

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		alice.equip(src.createMateria("ice"));
		alice.equip(src.createMateria("cure"));
		alice.unequip(0);
		printInventory(alice);
		alice.use(0, target);
		alice.unequip(0);
		alice.equip(src.createMateria("cure"));
		printInventory(alice);
		alice.use(0, target);
	}

	std::cout << "--- deep copy of Character ---" << std::endl;
	{
		MateriaSource	src;
		Character		target("target");

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		Character	original("original");
		original.equip(src.createMateria("ice"));
		original.equip(src.createMateria("cure"));

		Character	copy(original);
		original.unequip(0);
		printInventory(original);
		printInventory(copy);
		copy.use(0, target);

		Character	assigned("assigned");
		assigned.equip(src.createMateria("cure"));
		assigned.equip(src.createMateria("cure"));
		assigned.equip(src.createMateria("cure"));
		assigned = copy;
		copy.unequip(1);
		printInventory(copy);
		printInventory(assigned);
		std::cout << "materia pointers differ: "
			<< (assigned.getMateria(0) != copy.getMateria(0) ? "yes" : "no") << std::endl;
	}

	std::cout << "--- clone keeps the type ---" << std::endl;
	{
		Ice			ice;
		AMateria	*clone = ice.clone();
		Character	bob("bob");

		std::cout << "clone type: " << clone->getType() << std::endl;
		clone->use(bob);
		delete clone;
	}
	return 0;
}
