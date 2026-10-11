#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- subject test ---" << std::endl;
	{
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		delete j;
		delete i;
	}

	std::cout << "--- array of animals ---" << std::endl;
	{
		const int	size = 4;
		Animal		*animals[size];

		for (int k = 0; k < size; k++)
		{
			if (k < size / 2)
				animals[k] = new Dog();
			else
				animals[k] = new Cat();
		}
		for (int k = 0; k < size; k++)
		{
			std::cout << animals[k]->getType() << ": ";
			animals[k]->makeSound();
		}
		for (int k = 0; k < size; k++)
			delete animals[k];
	}

	std::cout << "--- deep copy (copy constructor) ---" << std::endl;
	{
		Dog	original;

		original.setIdea(0, "chase the cat");
		Dog	copy(original);
		copy.setIdea(0, "sleep all day");
		std::cout << "original idea: " << original.getIdea(0) << std::endl;
		std::cout << "copy idea:     " << copy.getIdea(0) << std::endl;
		std::cout << "brains differ: "
			<< (original.getBrain() != copy.getBrain() ? "yes" : "no") << std::endl;
	}

	std::cout << "--- deep copy (assignment operator) ---" << std::endl;
	{
		Cat	a;
		Cat	b;

		a.setIdea(0, "knock things off the table");
		b = a;
		b.setIdea(0, "ignore the human");
		std::cout << "a idea: " << a.getIdea(0) << std::endl;
		std::cout << "b idea: " << b.getIdea(0) << std::endl;
		std::cout << "brains differ: "
			<< (a.getBrain() != b.getBrain() ? "yes" : "no") << std::endl;
		Cat	&alias = b;
		b = alias;
		std::cout << "after self-assignment: " << b.getIdea(0) << std::endl;
	}

	std::cout << "--- copy going out of scope ---" << std::endl;
	{
		Dog	basic;

		basic.setIdea(1, "bury a bone");
		{
			Dog	tmp = basic;
		}
		std::cout << "basic still thinks: " << basic.getIdea(1) << std::endl;
	}

	std::cout << "--- out of range idea ---" << std::endl;
	{
		Cat	cat;

		cat.setIdea(100, "never stored");
		std::cout << "[" << cat.getIdea(100) << "]" << std::endl;
	}

	std::cout << "--- wrong animals ---" << std::endl;
	{
		const WrongAnimal	*w = new WrongCat();

		w->makeSound();
		delete w;
	}
	return 0;
}
