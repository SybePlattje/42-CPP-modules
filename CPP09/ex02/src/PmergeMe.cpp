#include "../include/PmergeMe.hpp"
#include <algorithm>
#include <iostream>

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
		*this = other;
	return *this;
}

PmergeMe::~PmergeMe() {};

int PmergeMe::JacobsthalNumber(int n)
{
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return this->JacobsthalNumber(n - 1) + 2 * this->JacobsthalNumber(n - 2);
}

//sort vector

std::vector<std::pair<int, int>> PmergeMe::vectorSetup(std::vector<int> ar)
{
	std::size_t size;
	if (ar.size() % 2 == 0) // checks  if the size if odd or even
		size = ar.size();
	else
		size = ar.size() - 1;
	std::vector<std::pair<int, int>> vec;
	vec.reserve(size / 2);
	std::vector<int>::iterator it = ar.begin();
	for (std::size_t i = 0; i < size; it++) // puts everything in pairs
	{
		int first = *it;
		++it;
		++i;
		int second = *it;
		++i;
		if (first > second) // largest number first
			vec.push_back(std::pair<int, int>(first, second));
		else
			vec.push_back(std::pair<int, int>(second, first));
	}
	if (ar.size() % 2 != 0)
		vec.push_back(std::pair<int, int>(*it, -1));
	std::sort(vec.begin(), vec.end(),
		[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.first < b.first;
	});
	return vec;
}

std::vector<int> PmergeMe::mergeSortVector(std::vector<std::pair<int, int>>& vec, std::size_t size)
{
	std::vector<int> main, pend;
	main.reserve(size);
	pend.reserve(vec.size());
	std::vector<std::pair<int, int>>::iterator it = vec.begin();
	bool flag = true;
	for (; it != vec.end(); it++)
	{
		if (flag)
		{
			if (it->second != -1)
				main.push_back(it->second);
			main.push_back(it->first);
			flag = false;
		}
		else
		{
			main.push_back(it->first);
			pend.push_back(it->second);
		}
	}
	int pSize = pend.size() - 1;
	int number = 3;
	int jacobNumber = this->JacobsthalNumber(number);
	int check = 0;
	while (check < pSize)
	{
		if (jacobNumber >= pSize)
			jacobNumber = pSize;
		for (int i = jacobNumber; i >= check; --i)
		{
			if (pend[i] != -1)
			{
				std::vector<int>::iterator before = std::upper_bound(main.begin(), main.end(), pend[i]);
				main.insert(before, pend[i]);
			}
		}
		check = jacobNumber;
		jacobNumber = this->JacobsthalNumber(++number);
	}
	return main;
}

//sort deque

std::deque<std::pair<int, int>> PmergeMe::dequeSetup(std::vector<int> ar)
{
	std::size_t size;
	if (ar.size() % 2 == 0) // checks  if the size if odd or even
		size = ar.size();
	else
		size = ar.size() -1;
	std::deque<std::pair<int, int>> deq;
	std::vector<int>::iterator it = ar.begin();
	for (std::size_t i = 0; i < size; it++) // puts everything in pairs
	{
		int first = *it;
		++it;
		++i;
		int second = *it;
		++i;
		if (first > second) // largest number first
			deq.push_back(std::pair<int, int>(first, second));
		else
			deq.push_back(std::pair<int, int>(second, first));
	}
	if (ar.size() % 2 != 0)
		deq.push_back(std::pair<int, int>(*it, -1));
	std::sort(deq.begin(), deq.end(),
		[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.first < b.first;
	});
	return deq;
}

std::deque<int> PmergeMe::mergeSortDeque(std::deque<std::pair<int, int>>& deq)
{
	std::deque<int> main, pend;
	std::deque<std::pair<int, int>>::iterator it = deq.begin();
	bool flag = true;
	for (; it != deq.end(); it++)
	{
		if (flag)
		{
			if (it->second != -1)
				main.push_back(it->second);
			main.push_back(it->first);
			flag = false;
		}
		else
		{
			main.push_back(it->first);
			pend.push_back(it->second);
		}
	}
	int pSize = pend.size() - 1;
	int number = 3;
	int jacobNumber = this->JacobsthalNumber(number);
	int check = 0;
	while (check < pSize)
	{
		if (jacobNumber >= pSize)
			jacobNumber = pSize;
		for (int i = jacobNumber; i >= check; --i)
		{
			if (pend[i] != -1)
			{
				std::deque<int>::iterator before = std::upper_bound(main.begin(), main.end(), pend[i]);
				main.insert(before, pend[i]);
			}
		}
		check = jacobNumber;
		jacobNumber = this->JacobsthalNumber(++number);
	}
	return main;
}
