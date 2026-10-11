#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : AAnimal(), _brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		Brain	*copy = new Brain(*other._brain);
		delete _brain;
		_brain = copy;
	}
	return *this;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}

const std::string	&Dog::getIdea(int idx) const
{
	return _brain->getIdea(idx);
}

void	Dog::setIdea(int idx, const std::string &idea)
{
	_brain->setIdea(idx, idea);
}

const Brain	*Dog::getBrain(void) const
{
	return _brain;
}
