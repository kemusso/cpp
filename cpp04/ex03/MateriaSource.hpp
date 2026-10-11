#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int	_slots = 4;
	AMateria			*_templates[_slots];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource	&operator=(const MateriaSource &other);
	~MateriaSource(void);

	void		learnMateria(AMateria *m);
	AMateria	*createMateria(const std::string &type);
};

#endif
