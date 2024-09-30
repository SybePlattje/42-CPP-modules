#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("jhon")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name)
{
	this->_grade = copy._grade;
}

Bureaucrat::~Bureaucrat() {};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
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

void Bureaucrat::signForm(Form& form)
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

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj)
{
	stream << obj.getName() << ", bureaucrats grade " << obj.getGrade();
	return stream;
}