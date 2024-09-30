#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Jhon")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name)
{
	this->_grade = copy._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

void Bureaucrat::signForm(AForm& form)
{
	if (!form.getSign() && this->getGrade() <= form.getGradeSign())
	{
		form.setSign(true);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	else if (form.getSign())
		std::cout << this->getName() << " couldn't sign " << form.getName() << " becayse it's already signed" << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because a grade equal or higner then " << form.getGradeSign() << " is needed, you have grade " << this->getGrade() << std::endl; 
}

int Bureaucrat::executeForm(const AForm& form)
{
	int can = form.execute(*this);
	switch (can)
	{
		case 0:
			std::cout << this->getName() << " executed " << form.getName() << std::endl;
			return 0;
		case 1:
			std::cout << this->getName() << " can't execute " << form.getName() << " because it isn't signed yet" << std::endl;
			return 1;
		default:
			std::cout << this->getName() << " can't execute " << form.getName() << " because your grade it too low" << std::endl;
			return 1;
	}
}