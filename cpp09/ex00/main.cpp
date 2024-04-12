#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./bitcoin [file]" << std::endl;
		return 1;
	}
	BitcoinExchange exchange;
	exchange.play(av[1]);
	return 0;
}