#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe::~PmergeMe() {
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src) {
	if (this != &src) {
		this->_vec = src._vec;
		this->_deq = src._deq;
	}
	return *this;
}

void PmergeMe::addNumbers(int argc, char **argv) {
	if (argc < 2)
		throw std::invalid_argument("Error : No arguments\n");
	for (int i = 1; i < argc; i++)
	{
		long long_temp = atol(argv[i]);
		std::string str(argv[i]);
		if (long_temp <= 0 || long_temp > 2147483647 || str.length() == 0)
			throw(std::logic_error("Error"));
		_vec.push_back(static_cast<int>(long_temp));
		_deq.push_back(static_cast<int>(long_temp));
	}
}

void PmergeMe::merge_vec(std::vector <long> &vec) {
	// 1. devide to main-chain and pending-chain
	if (vec.size() < 2)
		return;

	size_t                                  halfSize = vec.size() / 2;
	std::vector<long>                       mainChain;
	std::vector<long>                       pendingChain;
	std::vector< std::pair<long, long> >    vecPair;
	for (size_t i = 0; i < halfSize; ++i) {
		if (vec[i] > vec[i + halfSize]) {
			mainChain.push_back(vec[i]);
			pendingChain.push_back(vec[i + halfSize]);
		} else {
			mainChain.push_back(vec[i + halfSize]);
			pendingChain.push_back(vec[i]);
		}
		vecPair.push_back(std::make_pair(mainChain[i], pendingChain[i]));
	}
	if (vec.size() % 2 == 1)
		pendingChain.push_back(vec.back());

	// 2. recursive for main-chain and synchronize pending-chain from sorted-main-chain
	this->merge_vec(mainChain);
	if (mainChain.size() != 1) {
		for (size_t i = 0; i < mainChain.size(); ++i) {
			size_t findIdx = 0;
			while (mainChain[i] != vecPair[findIdx].first) findIdx++;
			pendingChain[i] = vecPair[findIdx].second;
		}
	}

	// 3. insert pending-chain to main-chain by sorting
	std::vector<long> sortedVec(mainChain);
	sortedVec.insert(sortedVec.begin(), pendingChain.front());
	size_t jacobIdx = 1;            // index(0) is already inserted to main
	size_t prev = 0, curr = 1;
	while (curr <= pendingChain.size() - 1) {
		curr = this->_jacobNum[jacobIdx++] - 1;
		if (curr >= pendingChain.size())
			curr = pendingChain.size() - 1;
		for (size_t i = curr; i > prev; --i) {
			size_t range;
			if (vec.size() % 2 == 1 && i == pendingChain.size() - 1)
				range = sortedVec.size();
			else
				range = std::lower_bound(sortedVec.begin(), sortedVec.end(), mainChain[i]) - sortedVec.begin();
			size_t insertPos = this->_searchInsertionPos(sortedVec, range, pendingChain[i]);
			sortedVec.insert(sortedVec.begin() + insertPos, pendingChain[i]);
		}
		prev = curr++;
	}
	vec = sortedVec;    // synchronization
}

void PmergeMe::merge_deque(std::deque<long> &dq) {
	// 1. devide to main-chain and pending-chain
	if (dq.size() < 2)
		return;

	size_t                                  halfSize = dq.size() / 2;
	std::deque<long>                       mainChain;
	std::deque<long>                       pendingChain;
	std::deque< std::pair<long, long> >    dqPair;
	for (size_t i = 0; i < halfSize; ++i) {
		if (dq[i] > dq[i + halfSize]) {
			mainChain.push_back(dq[i]);
			pendingChain.push_back(dq[i + halfSize]);
		} else {
			mainChain.push_back(dq[i + halfSize]);
			pendingChain.push_back(dq[i]);
		}
		dqPair.push_back(std::make_pair(mainChain[i], pendingChain[i]));
	}
	if (dq.size() % 2 == 1)
		pendingChain.push_back(dq.back());

	// 2. recursive for main-chain and synchronize pending-chain from sorted-main-chain
	this->merge_deque(mainChain);
	if (mainChain.size() != 1) {
		for (size_t i = 0; i < mainChain.size(); ++i) {
			size_t findIdx = 0;
			while (mainChain[i] != dqPair[findIdx].first) findIdx++;
			pendingChain[i] = dqPair[findIdx].second;
		}
	}

	// 3. insert pending-chain to main-chain by sorting
	std::deque<long> sortedDq(mainChain);
	sortedDq.insert(sortedDq.begin(), pendingChain.front());
	size_t jacobIdx = 1;            // index(0) is already inserted to main
	size_t prev = 0, curr = 1;
	while (curr <= pendingChain.size() - 1) {
		curr = this->_jacobNum[jacobIdx++] - 1;
		if (curr >= pendingChain.size())
			curr = pendingChain.size() - 1;
		for (size_t i = curr; i > prev; --i) {
			size_t range;
			if (dq.size() % 2 == 1 && i == pendingChain.size() - 1)
				range = sortedDq.size();
			else
				range = std::lower_bound(sortedDq.begin(), sortedDq.end(), mainChain[i]) - sortedDq.begin();
			size_t insertPos = this->_searchInsertionPos(sortedDq, range, pendingChain[i]);
			sortedDq.insert(sortedDq.begin() + insertPos, pendingChain[i]);
		}
		prev = curr++;
	}
	dq = sortedDq;    // synchronization
}

void PmergeMe::_calculateJacobsthalArr(size_t count)
{
	if (this->_jacobNum.empty() == false)
		this->_jacobNum.clear();
	this->_jacobNum.push_back(1);
	this->_jacobNum.push_back(3);
	size_t curr = 3, now = 2;
	while (curr <= count) {
		curr = this->_jacobNum[now - 1] + 2 * this->_jacobNum[now - 2];
		this->_jacobNum.push_back(curr);
		++now;
	}
}

size_t PmergeMe::_searchInsertionPos(std::vector<long>& sortedVec, size_t right, long insertValue)
{
	size_t left = 0;

	while (left < right) {
		size_t mid = (left + right) / 2;
		if (sortedVec[mid] > insertValue)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

size_t PmergeMe::_searchInsertionPos(std::deque<long>& sortedVec, size_t right, long insertValue)
{
	size_t left = 0;

	while (left < right) {
		size_t mid = (left + right) / 2;
		if (sortedVec[mid] > insertValue)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

void PmergeMe::check_duplicates() {
	std::vector<long> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 0; i < tmp.size() - 1; i++) {
		if (tmp[i] == tmp[i + 1])
			throw std::logic_error("Error : Duplicate numbers\n");
	}
}

void PmergeMe::print_vec(std::string msg) {
	std::cout << msg;
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
}

void PmergeMe::print_deque(std::string msg) {
	std::cout << msg;
	for (size_t i = 0; i < _deq.size(); i++)
		std::cout << _deq[i] << " ";
}

void PmergeMe::run(int argc, char **argv) {
	clock_t start, end;
	double timeTaken;

	addNumbers(argc, argv);
	check_duplicates();
	_calculateJacobsthalArr(_vec.size());
	print_vec("Before : ");
	std::cout << std::endl;
	print_vec("After : ");
	std::cout << std::endl;
	start = clock();
	merge_vec(_vec);
	end = clock();
	timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->_vec.size()
			  << " elements with std::[vector] : " << std::fixed << std::setprecision(6) << timeTaken << " us" << std::endl;
	start = clock();
	merge_deque(_deq);
	end = clock();
	timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->_deq.size()
			  << " elements with std::[deque] : " << std::fixed << std::setprecision(6) << timeTaken << " us" << std::endl;
}
