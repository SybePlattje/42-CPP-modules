#include "PhoneBook.hpp"

int main()
{
	PhoneBook book;
	std::string input;
	std::cout << "What would you like to do? SEARCH, ADD, or EXIT ";
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::clearerr(stdin);
			std::cin.clear();
		}
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0)
			book.searchContacts();
		else if (input.compare("EXIT") == 0)
			break;
		else
			std::cout << "ERROR: Please write an action you can do." << std::endl;
		std::cout << "What would you like to do? SEARCH, ADD, or EXIT ";
	}
}
