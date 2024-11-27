#include <iostream>
#include <sstream>
#include "../include/PmergeMe.hpp"
#include <chrono>
#include <iomanip>

std::vector<int> parseData(int argc, char *argv[])
{
	int number = 0;
	std::vector<int> ar;
	for (int index = 1; index < argc; index++)
	{
		std::stringstream readingString(argv[index]);
		if (!(readingString >> number) || !(readingString.eof()))
		{
			std::cerr << "Error: argv " << index << " is not a integer" << std::endl;
			return ar;
		}
		else if (number < 0)
		{
			std::cerr << "Error: argv " << index << " is a nagative integer" << std::endl;
			return ar;
		}
		ar.push_back(number);
	}
	return ar;
}

std::vector<int> solveWithVector(std::vector<int>& ar, std::chrono::duration<double, std::micro>& parseTime, double& vectorTime)
{
	PmergeMe pmM;
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::vector<std::pair<int, int>> vec = pmM.vectorSetup(ar);
	std::vector<int> sorted = pmM.mergeSortVector(vec, ar.size());
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vectorSortTime = end - start;
	vectorTime = (parseTime.count() + vectorSortTime.count());
	return sorted;
}

std::deque<int> solveWithDeque(std::vector<int>& ar, std::chrono::duration<double, std::micro>& parseTime, double& dequeTime)
{
	PmergeMe pmM;
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::deque<std::pair<int, int>> deq = pmM.dequeSetup(ar);
	std::deque<int> solvedDeq = pmM.mergeSortDeque(deq);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> dequeSortTime = end - start;
	dequeTime = (parseTime.count() + dequeSortTime.count());
	return solvedDeq;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: not the right amound of arguments!" << std::endl;
		return 1;
	}
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::vector<int> ar = parseData(argc, argv);
	if (ar.empty())
		return 1;
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> parseTime = end - start;
	std::cout << "Before: ";
	std::vector<int>::iterator it = ar.begin();
	for (; it != ar.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	double vectorTime = 0.0;
	std::vector<int> sorted = solveWithVector(ar, parseTime, vectorTime);
	std::vector<int>::iterator sit = sorted.begin();
	std::vector<int>::iterator site = sorted.end();
	std::cout << "After: ";
	for (; sit != site; ++sit)
	{
		std::cout << *sit << ' ';
	}
	std::cout << '\n';
	double dequeTime = 0.0;
	std::deque<int> sortedDeq = solveWithDeque(ar, parseTime, dequeTime);
	std::cout << "Time to process range of " << ar.size() << " with std::vector : " <<vectorTime << " us" << std::endl;
	std::cout << "Time to process range of " << ar.size() << " with std::deque : " << dequeTime << " us" << std::endl;
	return 0;
}
