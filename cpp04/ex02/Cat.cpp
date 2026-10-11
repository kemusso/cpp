#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : AAnimal(), _brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		Brain	*copy = new Brain(*other._brain);
		delete _brain;
		_brain = copy;
	}
	return *this;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}

const std::string	&Cat::getIdea(int idx) const
{
	return _brain->getIdea(idx);
}

void	Cat::setIdea(int idx, const std::string &idea)
{
	_brain->setIdea(idx, idea);
}

const Brain	*Cat::getBrain(void) const
{
	return _brain;
}
