#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	static const int	_maxContacts = 8;

	Contact	_contacts[_maxContacts];
	int		_count;
	int		_next;

public:
	PhoneBook();

	void	add();
	void	search() const;
};

#endif
