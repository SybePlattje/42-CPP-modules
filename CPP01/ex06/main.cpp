#include "HarlFilter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Wrong amound of argumants" << std::endl;
		return 1;
	}
	HarlFilter harl;
	harl.complain(argv[1]);
}