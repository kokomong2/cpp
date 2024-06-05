#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>

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
			value = std::stof(read.substr(date_size + 1));
			bitcoinData[read.substr(0, date_size)] = value;
		}
	}
}

bool BitcoinExchange::validateDate(const std::string &s) {
	if (s.length() != 10) return false;
	std::istringstream ss(s);
	std::string token;
	int year, month, day;

	std::getline(ss, token, '-');
	year = std::stoi(token);
	if (year < 1000 || year > 9999) return false;

	std::getline(ss, token, '-');
	month = std::stoi(token);
	if (month < 1 || month > 12) return false;

	std::getline(ss, token, '-');
	day = std::stoi(token);
	if (day < 1 || day > 31) return false;

	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) return false;
	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > 29 || (day == 29 && !isLeapYear)) return false;
	}

	return true;
}

void BitcoinExchange::bitcoin(char *file) {
	std::ifstream configfile(file);
	std::string read;
	getline(configfile, read);
	while (getline(configfile, read)) {
		checkInfo(read);
	}
}

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

	value = std::stof(valueStr);
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	printBit(date, value);
}

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

bool BitcoinExchange::validateInput(const std::string &s) {
	char *end;
	double value = std::strtod(s.c_str(), &end);
	if (*end != '\0') return false;
	if (value < 0) return false;
	return true;
}

void BitcoinExchange::play(char *file) {
	try {
		checkCsvFile();
		checkInputFile(file);
		bitcoin(file);
	} catch (const std::exception &e) {
		return;
	}
}
