#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

class BitcoinExchange {

private:
	std::map<std::string, float> bitcoinData;

	bool validateDate(const std::string &s); // Updated to return bool
	bool validateInput(const std::string &s); // Updated to return bool
	void checkCsvFile();
	void checkInputFile(char *file);
	void bitcoin(char *file);
	void checkInfo(const std::string &info); // Parameter type updated
	void printBit(const std::string &date, float n); // Parameter type updated

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange& operator=(const BitcoinExchange& ref);
	~BitcoinExchange();

	void play(char *file);

	class Error : public std::exception {
	public:
		const char* what() const throw();
	};
};

#endif
