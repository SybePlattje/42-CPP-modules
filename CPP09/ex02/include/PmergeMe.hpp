#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		int JacobsthalNumber(int n);
		// sort vector
		std::vector<std::pair<int, int>> vectorSetup(std::vector<int> ar);
		std::vector<int> mergeSortVector(std::vector<std::pair<int, int>>& vec, std::size_t size);
		// sort deque
		std::deque<std::pair<int, int>> dequeSetup(std::vector<int> ar);
		std::deque<int> mergeSortDeque(std::deque<std::pair<int, int>>& deq);
};

#endif