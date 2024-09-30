#include "File.hpp"

File::File(std::string fileName, std::string string1, std::string string2) 
{
	this->readFileName = fileName;
	this->stringToFind = string1;
	this->stringToReplace = string2;
}

File::~File() {};

void File::replace(const std::string outputFileName)
{
	std::ifstream inputFile(readFileName.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file: " << readFileName << std::endl;
		return;
	}
	std::ofstream outputFile(outputFileName.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error opening file: " << outputFileName << std::endl;
		return;
	}
	std::string line;
	while (std::getline(inputFile , line))
	{
		std::string newLine;
		size_t pos = 0;
		while (pos < line.length())
		{
			size_t foundPos = line.find(stringToFind, pos);
			if (foundPos == std::string::npos)
			{
				newLine += line.substr(pos);
				break;
			} 
			else
			{
				newLine += line.substr(pos, foundPos - pos);
				newLine += stringToReplace;
				pos = foundPos + stringToFind.length();
			}
		}
		outputFile << newLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
