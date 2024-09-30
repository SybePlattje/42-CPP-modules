#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <fstream>

class File
{
private:
	std::string readFileName;
	std::string stringToFind;
	std::string stringToReplace;
public:
	File(std::string, std::string, std::string);
	~File();
	void replace(const std::string);
};


#endif