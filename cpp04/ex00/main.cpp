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
		const Animal	*meta = new Animal();
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << "--- wrong animals through base pointer ---" << std::endl;
	{
		const WrongAnimal	*meta = new WrongAnimal();
		const WrongAnimal	*i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}

	std::cout << "--- WrongCat used as a WrongCat ---" << std::endl;
	{
		WrongCat	wc;

		wc.makeSound();
	}

	std::cout << "--- objects on the stack and references ---" << std::endl;
	{
		Dog		dog;
		Cat		cat;
		Animal	&ref = cat;

		std::cout << dog.getType() << ": ";
		dog.makeSound();
		std::cout << ref.getType() << " via Animal&: ";
		ref.makeSound();
	}

	std::cout << "--- copy and assignment ---" << std::endl;
	{
		Dog	a;
		Dog	b(a);
		Cat	c;
		Cat	d;

		d = c;
		std::cout << b.getType() << " " << d.getType() << std::endl;
		b.makeSound();
		d.makeSound();
	}
	return 0;
}
