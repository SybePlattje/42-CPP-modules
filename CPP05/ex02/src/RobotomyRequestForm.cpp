#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyForm", 72, 45)
{
	this->target = "name";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyForm", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy)
{
	this->target = copy.target;
}

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

void RobotomyRequestForm::doRobotics()
{
	std::cout << "*Drilling sounds!*" << std::endl;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);
	if (dis(gen))
		std::cout << target << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy on " << target << " failed!" << std::endl;
}

int RobotomyRequestForm::execute(const Bureaucrat& executor) const 
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