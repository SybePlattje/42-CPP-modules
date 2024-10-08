#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>
# include <iostream>

template <typename T> 
class Array
{
	private:
		T* data;
		unsigned int size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array&);
		Array& operator=(const Array&);
		 T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		~Array();
		unsigned int Size();
};

# include "../src/Array.tpp"
#endif