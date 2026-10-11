#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_brain;

public:
	Dog(void);
	Dog(const Dog &other);
	Dog	&operator=(const Dog &other);
	~Dog(void);

	void				makeSound(void) const;
	const std::string	&getIdea(int idx) const;
	void				setIdea(int idx, const std::string &idea);
	const Brain			*getBrain(void) const;
};

#endif
