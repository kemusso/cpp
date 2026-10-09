#include "PhoneBook.hpp"
#include <cctype>
#include <iostream>
#include <iomanip>

static std::string	truncate(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

static bool	hasControlChar(const std::string &s)
{
	for (std::string::size_type i = 0; i < s.length(); i++)
	{
		if (std::iscntrl(static_cast<unsigned char>(s[i])))
			return true;
	}
	return false;
}

static bool	isAllDigits(const std::string &s)
{
	for (std::string::size_type i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}

static bool	readField(const std::string &prompt, std::string &out, bool digitsOnly)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return false;
		if (hasControlChar(out))
			std::cout << "Tabs and control characters are not allowed." << std::endl;
		else if (out.find_first_not_of(' ') == std::string::npos)
			std::cout << "This field cannot be empty." << std::endl;
		else if (digitsOnly && !isAllDigits(out))
			std::cout << "Only digits are allowed." << std::endl;
		else
			return true;
	}
}

PhoneBook::PhoneBook() : _count(0), _next(0)
{
}

bool	PhoneBook::add()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (!readField("First name: ", firstName, false)
		|| !readField("Last name: ", lastName, false)
		|| !readField("Nickname: ", nickname, false)
		|| !readField("Phone number: ", phoneNumber, true)
		|| !readField("Darkest secret: ", darkestSecret, false))
		return false;

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
	return true;
}

bool	PhoneBook::search() const
{
	if (_count == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return true;
	}

	std::cout << std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|"
			<< std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
	}

	std::string	input;
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return false;
	if (input.length() != 1 || input[0] < '1' || input[0] > '0' + _count)
	{
		std::cout << "Invalid index." << std::endl;
		return true;
	}

	const Contact	&c = _contacts[input[0] - '1'];
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
	return true;
}
