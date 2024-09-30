#ifndef CONTACT_HPP
# define CONTACT_HPP
# ifndef IOSTREAM
#  include <iostream>
#  define IOSTREAM
# endif
class Contact
{
private:
	int id;
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
public:
	Contact();
	Contact(int id, std::string first, std::string last, std::string nick, std::string phone, std::string darkSecret);
	~Contact();
	Contact const *getContect() const;
	void setContact(int id, std::string first, std::string last, std::string nick, std::string phone, std::string darkSecret);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getSecret();
};

#endif