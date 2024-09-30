#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <iostream>

struct Data
{
	std::string str;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		~Serializer();
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
};

#endif