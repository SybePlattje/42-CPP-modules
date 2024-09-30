#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif
# include <iomanip>
# include <cstdio>

class PhoneBook
{
private:
	int index;
	Contact contacts[8];
public:
	PhoneBook();
	~PhoneBook();
	void setContact(std::string, std::string, std::string, std::string, std::string);
	Contact getContact(int) const;
	Contact *getAll();
	void addContact();
	std::string setValue(std::string);
	void searchContacts();
	void printContact(Contact);
};

#endif