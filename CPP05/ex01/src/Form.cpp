#include "../include/Form.hpp"

Form::Form(): _name("Form"), _gradeSign(150), _gradeExe(150)
{
	this->_sign = false;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExe): _name(name), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (this->_gradeSign < 1)
		throw GradeTooHighException();
	else if (this->_gradeSign > 150)
		throw GradeTooLowException();
	if (this->_gradeExe < 1)
		throw GradeTooHighException();
	else if (this->_gradeExe > 150)
		throw GradeTooLowException();
	this->_sign = false;
}

Form::Form(const Form& copy): _name(copy._name), _gradeSign(copy._gradeSign), _gradeExe(copy._gradeExe)
{
	if (this->_gradeSign < 1)
		throw GradeTooHighException();
	else if (this->_gradeSign > 150)
		throw GradeTooLowException();
	if (this->_gradeExe < 1)
		throw GradeTooHighException();
	else if (this->_gradeExe > 150)
		throw GradeTooLowException();
	this->_sign = copy._sign;
} 

Form::~Form() {};

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_sign = other._sign;
	return *this;
}

const std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSign() const
{
	return this->_sign;
}

void Form::setSign(bool sign)
{
	this->_sign = sign;
}

int Form::getGradeSign() const
{
	return this->_gradeSign;
}

int Form::getGradeExe() const
{
	return this->_gradeExe;
}

bool Form::beSigned(Bureaucrat& person)
{
	if (person.getGrade() <= this->_gradeSign)
	{
		if (!this->_sign)
		{
			this->_sign = true;
			return true;
		}
		else
			return false;
	}
	else
		throw GradeTooLowException();
	throw NotSignedException();
	return false;
}

std::ostream& operator<<(std::ostream& out, Form& obj)
{
	out << obj.getName() << " has a sign grade of " << obj.getGradeSign() << " and a execute grade of " << obj.getGradeExe() << " and it's sign state is " << obj.getSign();
	return out;
}