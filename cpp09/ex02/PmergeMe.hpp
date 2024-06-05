#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <ctime>
#include <iomanip>
#include <algorithm>

class PmergeMe {

private:
	std::vector<long> _vec;
	std::deque<long> _deq;
	std::vector<size_t> _jacobNum;

	void _calculateJacobsthalArr(size_t count);

	size_t  _searchInsertionPos(std::vector<long>& sortedVec, size_t right, long insertValue);
	size_t  _searchInsertionPos(std::deque<long>& sortedDq, size_t right, long insertValue);
public:
	PmergeMe();
	PmergeMe(PmergeMe const & src);
	~PmergeMe();
	PmergeMe & operator=(PmergeMe const & src);

	void run(int argc, char **argv);
	void addNumbers(int argc, char **argv);

	void merge_vec(std::vector<long> &vec);
	void merge_deque(std::deque<long> &deq);

	void check_duplicates();

	void print_vec(std::string msg);
	void print_deque(std::string msg);
};

#endif
