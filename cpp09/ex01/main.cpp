#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./rpn [expression]" << std::endl;
		return 1;
	}
	RPN rpn(av[1]);
	rpn.play();
	return 0;
}