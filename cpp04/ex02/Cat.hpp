#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*_brain;

public:
	Cat(void);
	Cat(const Cat &other);
	Cat	&operator=(const Cat &other);
	~Cat(void);

	void				makeSound(void) const;
	const std::string	&getIdea(int idx) const;
	void				setIdea(int idx, const std::string &idea);
	const Brain			*getBrain(void) const;
};

#endif
