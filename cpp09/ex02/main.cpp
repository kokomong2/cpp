#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe p;
	try {
		p.run(argc, argv);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}