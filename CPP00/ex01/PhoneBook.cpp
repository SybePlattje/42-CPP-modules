#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::setContact(std::string first, std::string last, std::string nick, std::string phone, std::string darkSecret)
{
	this->contacts[index].setContact(index, first, last, nick, phone, darkSecret);
}

Contact PhoneBook::getContact(int i) const
{
	return this->contacts[i];
}

Contact *PhoneBook::getAll()
{
	return this->contacts;
}

void PhoneBook::addContact()
{
	std::string first = setValue("firstname = ");
	std::string last = setValue("Lastname = ");
	std::string nick = setValue("Nickname = ");
	std::string phone = setValue("Phone Number = ");
	std::string darkSercet = setValue("Secret = ");

	this->setContact(first, last, nick, phone, darkSercet);
	if (this->index >= 7)
		this->index = 0;
	else
		this->index++;
}

std::string PhoneBook::setValue(std::string text)
{
	std::string output;
	while (output.empty())
	{
		std::cout << text;
		if (std::cin.eof() || std::cin.fail())
		{
			std::clearerr(stdin);
			std::cin.clear();
		}
		std::getline(std::cin, output);
		if (output.empty())
			std::cout << "Error: Please enter a non-empty string." << std::endl;
	}
	return output;
}

void PhoneBook::printContact(Contact person)
{
	std::cout << "Fistname = " << person.getFirstName() << std::endl;
	std::cout << "Lastname = " << person.getLastName() << std::endl;
	std::cout << "Nickname = " << person.getNickName() << std::endl;
	std::cout << "Phone Number = " << person.getPhoneNumber() << std::endl;
	std::cout << "Secret = " << person.getSecret() << std::endl;
}

void PhoneBook::searchContacts()
{
	Contact *persons = getAll();
	int i = 0;
	while (i < 8)
	{
		Contact person = persons[i];
		if (person.getFirstName().empty())
			break;
		std::cout << std::setw(10);
		std::cout << i + 1 << "|";
		if (person.getFirstName().length() > 9)
			std::cout << person.getFirstName().substr(0, 9) << ".";
		else
		{
			std::cout << std::setw(10);
			std::cout << person.getFirstName();
		}
		std::cout << "|";
		if (person.getLastName().length() > 9)
			std::cout << person.getLastName().substr(0, 9) << ".";
		else
		{
			std::cout << std::setw(10);
			std::cout << person.getLastName();
		}
		std::cout << "|";
		if (person.getNickName().length() > 9)
			std::cout << person.getNickName().substr(0, 9) << "." << std::endl;
		else
		{
			std::cout << std::setw(10);
			std::cout << person.getNickName() << std::endl;
		}
		i++;
	}
	if (i != 0)
	{
		std::string input;
		do
		{
			std::cout << "Please enter the entry id you want to see.";
			if (std::cin.eof() || std::cin.fail())
			{
				std::clearerr(stdin);
				std::cin.clear();
			}
			std::getline(std::cin, input);
			if (input.empty(), input.length() != 1 || input[0] < '1' || input[0] > (i + '0') )
				std::cout << "ERROR: Please write a number of an existing member." << std::endl;
		} while (input.empty() || input.length() != 1 || input[0] < '1' || input[0] > (i + '0'));
		int number = input[0] - '0';
		Contact person = getContact(number - 1);
		printContact(person);
	}
	else
		std::cout << "No contacts are in this phonebook yet." << std::endl;
}
