#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(int number, std::string first, std::string last, std::string nick, std::string phone, std::string darkSecret)
{
	this->id = number;
	this->firstname = first;
	this->lastname = last;
	this->nickname = nick;
	this->phoneNumber = phone;
	this->secret = darkSecret;
}

Contact::~Contact()
{

}

void Contact::setContact(int index, std::string first, std::string last, std::string nick, std::string phone, std::string darkSecret)
{
	this->id = index;
	this->firstname = first;
	this->lastname = last;
	this->nickname = nick;
	this->phoneNumber = phone;
	this->secret = darkSecret;
}

Contact const *Contact::getContect() const
{
	Contact const *person = this;
	return person;
}

std::string Contact::getFirstName()
{
	return this->firstname;
}

std::string Contact::getLastName()
{
	return this->lastname;
}

std::string Contact::getNickName()
{
	return this->nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

std::string Contact::getSecret()
{
	return this->secret;
}
