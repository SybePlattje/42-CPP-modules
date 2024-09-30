#include "../include/Serializer.hpp"

int main(void)
{

	std::string hello = "hello";
	Data* data = new Data();
	data->str = hello;
	uintptr_t serialized =  Serializer::serialize(data);
	std::cout << serialized << std::endl;
	Data* dat = Serializer::deserialize(serialized);
	std::cout << dat->str << std::endl;
	delete data;
}