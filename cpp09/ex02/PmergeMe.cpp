#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator=(PmergeMe const & src) {
	if (this != &src) {
		this->_vec = src._vec;
		this->_deq = src._deq;
	}
	return *this;
}

/**
 * @brief 입력된 숫자들을 벡터와 덱에 추가하는 함수
 *
 * 이 함수는 프로그램의 인자로 전달된 숫자들을 벡터와 덱에 추가합니다.
 * 각 숫자가 유효한지 확인하고, 유효하지 않은 경우 예외를 발생시킵니다.
 */
void PmergeMe::addNumbers(int argc, char **argv) {
	if (argc < 2)
		throw std::invalid_argument("Error : No arguments\n");
	for (int i = 1; i < argc; i++) {
		long long_temp = atol(argv[i]);
		std::string str(argv[i]);
		if (long_temp <= 0 || long_temp > 2147483647 || str.length() == 0)
			throw(std::logic_error("Error"));
		_vec.push_back(static_cast<int>(long_temp));
		_deq.push_back(static_cast<int>(long_temp));
	}
}

// 1. 벡터를 메인 체인과 팬딩 체인으로 분리
// 2. 재귀적으로 메인 체인을 정렬하고, 팬딩 체인을 정렬된 메인 체인과 동기화
// 3. 팬딩 체인을 메인 체인에 삽입하면서 정렬
void PmergeMe::merge_vec(std::vector<long>& vec) {
	// 벡터의 크기가 2보다 작으면 이미 정렬되어 있으므로 종료
	if (vec.size() < 2)
		return;

	// 벡터의 절반 크기를 계산
	size_t halfSize = vec.size() / 2;

	// 메인 체인과 팬딩 체인을 저장할 벡터를 선언
	std::vector<long> mainChain;
	std::vector<long> pendingChain;

	// 쌍(pair)을 저장할 벡터를 선언
	std::vector< std::pair<long, long> > vecPair;

	// 벡터의 절반을 순회하면서 각 요소를 쌍으로 만듬
	for (size_t i = 0; i < halfSize; ++i) {
		// 각 쌍의 더 큰 값을 메인 체인에, 더 작은 값을 팬딩 체인에 추가
		if (vec[i] > vec[i + halfSize]) {
			mainChain.push_back(vec[i]);
			pendingChain.push_back(vec[i + halfSize]);
		} else {
			mainChain.push_back(vec[i + halfSize]);
			pendingChain.push_back(vec[i]);
		}
		// 쌍을 vecPair 벡터에 추가
		vecPair.push_back(std::make_pair(mainChain[i], pendingChain[i]));
	}

	// 벡터의 크기가 홀수인 경우 팬딩 체인에 마지막 요소를 추가
	if (vec.size() % 2 == 1)
		pendingChain.push_back(vec.back());

	// 여기까지가 메인 체인, 팬딩 체인을 나누는 작업

	// 메인 체인을 재귀적으로 정렬
	this->merge_vec(mainChain);

	// 정렬된 메인 체인에 따라 팬딩 체인을 동기화
	// 메인 체인이랑 팬딩 체인은 원래 쌍으로 이어져 있으므로 이를 찾아서 동기화하는 작업
	if (mainChain.size() != 1) {
		for (size_t i = 0; i < mainChain.size(); ++i) {
			size_t findIdx = 0;
			while (mainChain[i] != vecPair[findIdx].first) findIdx++;
			pendingChain[i] = vecPair[findIdx].second;
		}
	}

	// 정렬된 메인 체인을 기반으로 팬딩 체인을 정렬된 벡터에 삽입
	std::vector<long> sortedVec(mainChain);

	// 팬딩 체인의 첫 번째 요소를 정렬된 벡터의 시작 위치에 삽입
	sortedVec.insert(sortedVec.begin(), pendingChain.front());

	// Jacobsthal 수열의 인덱스를 초기화
	size_t jacobIdx = 1;
	size_t prev = 0, curr = 1; // prev는 이전에 삽입된 요소의 인덱스, curr는 현재 삽입할 요소의 인덱스

	// 팬딩 체인의 나머지 요소들을 정렬된 벡터에 삽입
	while (curr <= pendingChain.size() - 1) {
		curr = this->_jacobNum[jacobIdx++] - 1;
		if (curr >= pendingChain.size())
			curr = pendingChain.size() - 1;
		// 이진 탐색을 통해 삽입 위치를 찾아 삽입
		for (size_t i = curr; i > prev; --i) {
			size_t insertPos = this->_searchInsertionPos(sortedVec, sortedVec.size(), pendingChain[i]);
			sortedVec.insert(sortedVec.begin() + insertPos, pendingChain[i]);
		}
		prev = curr++;
	}

	// 정렬된 벡터를 원래 벡터에 동기화
	vec = sortedVec;
}

void PmergeMe::merge_deque(std::deque<long>& dq) {
	if (dq.size() < 2)
		return;

	size_t halfSize = dq.size() / 2;
	std::deque<long> mainChain;
	std::deque<long> pendingChain;
	std::deque< std::pair<long, long> > dqPair;
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

	this->merge_deque(mainChain);
	if (mainChain.size() != 1) {
		for (size_t i = 0; i < mainChain.size(); ++i) {
			size_t findIdx = 0;
			while (mainChain[i] != dqPair[findIdx].first) findIdx++;
			pendingChain[i] = dqPair[findIdx].second;
		}
	}

	std::deque<long> sortedDq(mainChain);
	sortedDq.insert(sortedDq.begin(), pendingChain.front());
	size_t jacobIdx = 1;
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
	dq = sortedDq;
}

/**
 * @brief Jacobsthal 수열을 계산하는 함수
 *
 * 이 함수는 주어진 크기(count)만큼 Jacobsthal 수열을 계산하여 저장합니다.
 */
void PmergeMe::_calculateJacobsthalArr(size_t count) {
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

/**
 * @brief 벡터에서 삽입 위치를 찾는 함수
 *
 * 이 함수는 정렬된 벡터에서 주어진 값(insertValue)을 삽입할 위치를 이진 탐색을 사용하여 찾습니다.
 */
size_t PmergeMe::_searchInsertionPos(std::vector<long>& sortedVec, size_t right, long insertValue) {
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

/**
 * @brief 덱에서 삽입 위치를 찾는 함수
 *
 * 이 함수는 벡터에서 삽입 위치를 찾는 함수와 동일한 방식으로 작동하며,
 * 덱을 사용하여 이진 탐색을 수행합니다.
 */
size_t PmergeMe::_searchInsertionPos(std::deque<long>& sortedVec, size_t right, long insertValue) {
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
	start = clock();
	merge_vec(_vec);
	end = clock();
	print_vec("After : ");
	std::cout << std::endl;
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
