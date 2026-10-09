#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (true)
	{
		std::cout << "Command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
		{
			if (!phoneBook.add())
				break ;
		}
		else if (command == "SEARCH")
		{
			if (!phoneBook.search())
				break ;
		}
		else if (command == "EXIT")
			break ;
	}
	return 0;
}
