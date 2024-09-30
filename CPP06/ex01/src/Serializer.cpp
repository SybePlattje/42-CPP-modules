#include "../include/Serializer.hpp"

uintptr_t Serializer::serialize(Data* data)
{
	uintptr_t ptr = reinterpret_cast<uintptr_t>(data);
	return ptr;
}

Data* Serializer::deserialize(uintptr_t uintptr)
{
	Data* data = reinterpret_cast<Data *>(uintptr);
	return data;
}


Serializer::~Serializer() {};

Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
		*this = other;
	return *this;
}