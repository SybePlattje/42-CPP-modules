#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template<typename T>
void iter(T* start, std::size_t size, void (*func)(T))
{
	for (std::size_t i = 0; i < size; i++)
		func(start[i]);
}

template<typename T>
void iter(T* start, std::size_t size, void (*func)(const T&))
{
	for (std::size_t i = 0; i < size; i++)
		func(start[i]);
}

#endif