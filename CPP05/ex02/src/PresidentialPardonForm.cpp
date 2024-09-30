#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon", 25, 5)
{
	this->target = "name";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy)
{
	this->target = copy.target;
}

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

void PresidentialPardonForm::pardon()
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

int PresidentialPardonForm::execute(const Bureaucrat& executor) const 
{
	if (!this->getSign())
	{
		throw NotSignedException();
		return 1;
	}
	if (this->getGradeExe() < executor.getGrade())
		throw GradeTooLowException();
	return 0;
}