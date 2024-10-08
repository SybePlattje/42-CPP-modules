template <typename T>
Array<T>::Array(): data(nullptr), size(0) {};

template <typename T>
Array<T>::Array(unsigned int n): data(new T[n]{}), size(n) {};

template <typename T>
Array<T>::Array(const Array& copy): data(nullptr), size(0)
{
	if (copy.size > 0)
	{
		this->data = new T[copy.size];
		this->size = copy.size;
		for (unsigned int i = 0; i < this->size; ++i)
			this->data[i] = copy.data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] this->data;
		if (other.size != 0)
		{
			this->data = new T[other.size];
			this->size = other.size;
			for (unsigned int i = 0; i < this->size; ++i)
				this->data[i] = other.data[i];
		}
		else
		{
			this->data = nullptr;
			this->size = 0;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->size)
		throw std::out_of_range("index out of bounds");
	return this->data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->size)
		throw std::out_of_range("index out of bounds");
	return this->data[index];
}

template <typename T>
unsigned int Array<T>::Size()
{
	return this->size;
}
