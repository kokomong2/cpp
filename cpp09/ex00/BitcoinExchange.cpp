#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src) {
		bitcoinData = src.bitcoinData;
	}
	return (*this);
}

const char *BitcoinExchange::Error::what() const throw() {
	return "Error";
}

// 입력 파일의 형식을 확인하는 함수
void BitcoinExchange::checkInputFile(char *file) {
	std::fstream fs;
	std::string str;

	fs.open(file, std::ifstream::in);
	if (!fs.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		throw Error();
	}

	if (std::getline(fs, str).eof()) {
		std::cout << "Error: File empty or no data in." << std::endl;
		throw Error();
	}

	if (str.compare("date | value") != 0) {
		std::cout << "Error: File format error." << std::endl;
		throw Error();
	}

	fs.close();
}

// CSV 파일을 읽고 데이터를 로드하는 함수
void BitcoinExchange::checkCsvFile() {
	std::ifstream csv("data.csv");
	std::string read;
	size_t date_size;
	float value;

	if (!csv) {
		std::cout << "Error: could not open database file." << std::endl;
		throw Error();
	}

	if (std::getline(csv, read).eof()) {
		std::cout << "Error: file empty or no data in." << std::endl;
		throw Error();
	}

	while (std::getline(csv, read)) {
		if (read != "date,exchange_rate") {
			date_size = read.find(',');
			if (!validateDate(read.substr(0, date_size))) {
				std::cout << "Error: include invalid date." << std::endl;
				throw Error();
			}
			if (!validateInput(read.substr(date_size + 1))) {
				std::cout << "Error: include invalid value." << std::endl;
				throw Error();
			}
			std::istringstream iss(read.substr(date_size + 1));
			iss >> value;
			bitcoinData[read.substr(0, date_size)] = value;
		}
	}
}

// 날짜 형식을 확인하는 함수
bool BitcoinExchange::validateDate(const std::string &s) {
	if (s.length() != 10) return false;
	std::istringstream ss(s);
	std::string token;
	int year, month, day;

	std::getline(ss, token, '-');
	std::istringstream(token) >> year;
	if (year < 1000 || year > 9999) return false;

	std::getline(ss, token, '-');
	std::istringstream(token) >> month;
	if (month < 1 || month > 12) return false;

	std::getline(ss, token, '-');
	std::istringstream(token) >> day;
	if (day < 1 || day > 31) return false;

	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) return false;
	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > 29 || (day == 29 && !isLeapYear)) return false;
	}

	return true;
}

// 입력 파일을 처리하는 함수
void BitcoinExchange::bitcoin(char *file) {
	std::ifstream configfile(file);
	std::string read;
	getline(configfile, read);
	while (getline(configfile, read)) {
		checkInfo(read);
	}
}

// 입력 파일의 한 줄을 확인하고 처리하는 함수
void BitcoinExchange::checkInfo(const std::string &info) {
	std::istringstream formats(info);
	std::string date, valueStr, separator;
	float value;

	formats >> date >> separator >> valueStr;

	if (separator != "|") {
		std::cout << "Error: bad input => " << info << std::endl;
		return;
	}

	if (!validateDate(date)) {
		std::cout << "Error: invalid date format => " << info << std::endl;
		return;
	}

	if (!validateInput(valueStr)) {
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}

	std::istringstream(valueStr) >> value;
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	printBit(date, value);
}

// 비트코인 값을 계산하고 출력하는 함수
void BitcoinExchange::printBit(const std::string &date, float n) {
	std::map<std::string, float>::const_iterator iter;
	float res = 0;
	iter = bitcoinData.find(date);
	if (iter != bitcoinData.end()) {
		res = iter->second * n;
	} else {
		iter = bitcoinData.lower_bound(date);
		if (iter == bitcoinData.begin()) {
			std::cout << "Error: invalid date" << std::endl;
			return;
		}
		--iter;
		res = iter->second * n;
	}

	if (n == static_cast<int>(n)) {
		std::cout << date << " => " << static_cast<int>(n) << " = " << res << std::endl;
	} else {
		std::cout << date << " => " << n << " = " << res << std::endl;
	}
}

// 입력 값을 확인하는 함수
bool BitcoinExchange::validateInput(const std::string &s) {
	std::istringstream iss(s);
	float value;
	iss >> value;
	if (iss.fail() || !iss.eof()) return false;
	if (value < 0) return false;
	return true;
}

// 프로그램을 실행하는 함수
void BitcoinExchange::play(char *file) {
	try {
		checkCsvFile();
		checkInputFile(file);
		bitcoin(file);
	} catch (const std::exception &e) {
		return;
	}
}
