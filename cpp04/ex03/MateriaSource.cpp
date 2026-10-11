#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < _slots; i++)
		_templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < _slots; i++)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = 0;
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < _slots; i++)
		{
			delete _templates[i];
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = 0;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < _slots; i++)
		delete _templates[i];
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < _slots; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m->clone();
			delete m;
			return ;
		}
	}
	delete m;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < _slots; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return 0;
}
