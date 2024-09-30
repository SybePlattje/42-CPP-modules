#include "../include/AForm.hpp"

AForm::AForm(): _name("form"), _gradeSign(150), _gradeExe(150)
{
	this->_sign = false;
}

AForm::AForm(const std::string name, const int exeGrade, const int signGrade): _name(name), _gradeSign(signGrade), _gradeExe(exeGrade)
{
	this->_sign = false;
}

AForm::AForm(const AForm& copy): _name(copy._name), _gradeSign(copy._gradeSign), _gradeExe(copy._gradeExe)
{
	this->_sign = copy._sign;
}

AForm::~AForm() {};

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_sign = other._sign;
	return *this;
}

bool AForm::getSign() const
{
	return this->_sign;
}

const std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeSign() const
{
	return this->_gradeSign;
}

int AForm::getGradeExe() const
{
	return this->_gradeExe;
}

void AForm::setSign(bool sign)
{
	this->_sign = sign;
}

bool AForm::beSigned(Bureaucrat& person)
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
	return false;
}

