#include "File.hpp"

int main (int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Please provide a filename and 2 strings" <<std::endl;
		return 1;
	}
	std::string filePath = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	File file(filePath, s1, s2);
	file.replace(filePath+".replace");
}