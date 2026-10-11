#include "Character.hpp"

Character::Character(void) : _name("default"), _floor(0), _floorSize(0)
{
	for (int i = 0; i < _slots; i++)
		_inventory[i] = 0;
}

Character::Character(const std::string &name)
	: _name(name), _floor(0), _floorSize(0)
{
	for (int i = 0; i < _slots; i++)
		_inventory[i] = 0;
}

Character::Character(const Character &other)
	: _name(other._name), _floor(0), _floorSize(0)
{
	for (int i = 0; i < _slots; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		_clearInventory();
		for (int i = 0; i < _slots; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character(void)
{
	_clearInventory();
	for (int i = 0; i < _floorSize; i++)
		delete _floor[i];
	delete[] _floor;
}

void	Character::_clearInventory(void)
{
	for (int i = 0; i < _slots; i++)
	{
		delete _inventory[i];
		_inventory[i] = 0;
	}
}

void	Character::_dropOnFloor(AMateria *m)
{
	AMateria	**bigger = new AMateria*[_floorSize + 1];

	for (int i = 0; i < _floorSize; i++)
		bigger[i] = _floor[i];
	bigger[_floorSize] = m;
	delete[] _floor;
	_floor = bigger;
	_floorSize++;
}

const std::string	&Character::getName(void) const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < _slots; i++)
	{
		if (_inventory[i] == m)
			return ;
	}
	for (int i = 0; i < _slots; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= _slots || !_inventory[idx])
		return ;
	_dropOnFloor(_inventory[idx]);
	_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= _slots || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
}

const AMateria	*Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= _slots)
		return 0;
	return _inventory[idx];
}
