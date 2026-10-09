#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

static std::string	truncate(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

static bool	readField(const std::string &prompt, std::string &out)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return false;
		if (!out.empty())
			return true;
		std::cout << "This field cannot be empty." << std::endl;
	}
}

PhoneBook::PhoneBook() : _count(0), _next(0)
{
}

void	PhoneBook::add()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (!readField("First name: ", firstName)
		|| !readField("Last name: ", lastName)
		|| !readField("Nickname: ", nickname)
		|| !readField("Phone number: ", phoneNumber)
		|| !readField("Darkest secret: ", darkestSecret))
		return ;

	Contact	&slot = _contacts[_next];
	slot.setFirstName(firstName);
	slot.setLastName(lastName);
	slot.setNickname(nickname);
	slot.setPhoneNumber(phoneNumber);
	slot.setDarkestSecret(darkestSecret);

	_next = (_next + 1) % _maxContacts;
	if (_count < _maxContacts)
		_count++;
	std::cout << "Contact saved." << std::endl;
}

void	PhoneBook::search() const
{
	if (_count == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
	}

	std::string	input;
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.length() != 1 || input[0] < '0' || input[0] >= '0' + _count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	const Contact	&c = _contacts[input[0] - '0'];
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}
