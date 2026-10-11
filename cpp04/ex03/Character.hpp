#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	static const int	_slots = 4;
	std::string			_name;
	AMateria			*_inventory[_slots];
	AMateria			**_floor;
	int					_floorSize;

	void	_clearInventory(void);
	void	_dropOnFloor(AMateria *m);

public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &other);
	Character	&operator=(const Character &other);
	~Character(void);

	const std::string	&getName(void) const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
	const AMateria		*getMateria(int idx) const;
};

#endif
