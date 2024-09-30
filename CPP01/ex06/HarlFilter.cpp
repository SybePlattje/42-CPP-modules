#include "HarlFilter.hpp"

//public

HarlFilter::HarlFilter() {};

HarlFilter::~HarlFilter() {};

void HarlFilter::complain(std::string level)
{
	int number = 0;
	std::string complaintLeves[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	while (number < 4)
	{
		if (level == complaintLeves[number])
			break;
		number++;
	}
	switch (number)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ] "<< std::endl;
			break;
	}
}

//private

void HarlFilter::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void HarlFilter::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void HarlFilter::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void HarlFilter::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
