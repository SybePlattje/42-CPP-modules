#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

class ElementNotFoundException: public std::exception
{
	public:
		const char* what() const throw()
		{
			return "Element not found in container";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw ElementNotFoundException();
	}
	return it;
}


#endif