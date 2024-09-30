#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

# include <iostream>

class HarlFilter
{
private:
	void debug();
	void info();
	void warning();
	void error();
public:
	HarlFilter();
	~HarlFilter();
	void complain(std::string);
};

#endif