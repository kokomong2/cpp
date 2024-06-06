#include "RPN.hpp"

RPN::RPN() : stringArgv(""), numberOfValues(0) {}

RPN::RPN(char *av) : stringArgv(av), numberOfValues(0) {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src) {
		stringArgv = src.stringArgv;
		rpn = src.rpn;
		splitString = src.splitString;
		numberOfValues = src.numberOfValues;
	}
	return (*this);
}

/**
 * @brief 문자열을 공백을 기준으로 분리하여 스택에 저장하고 입력을 검증하는 함수
 *
 * 이 함수는 입력된 RPN 표현식을 공백을 기준으로 분리하여 각 토큰을 스택에 저장합니다.
 * 또한, 각 토큰이 유효한 입력인지 검증합니다. 검증 과정에서 숫자의 개수를 카운트하고,
 * 전체 토큰의 개수와 비교하여 유효한 RPN 표현식인지 확인합니다.
 */
void RPN::split() {
	std::istringstream ss(this->stringArgv);
	std::string stringBuffer;
	std::stack<std::string> tmp;
	while (std::getline(ss, stringBuffer, ' ')) {
		if (stringBuffer.empty()) continue;
		tmp.push(stringBuffer);
	}

	this->numberOfValues = 0;
	while (!tmp.empty()) {
		this->splitString.push(tmp.top());
		validateInput(tmp.top());
		tmp.pop();
	}

	if (2 * this->numberOfValues - this->splitString.size() != 1) throw RPN::Error();
}

/**
 * @brief 입력된 문자열이 유효한 숫자 또는 연산자인지 확인하는 함수
 *
 * 주어진 문자열이 연산자인지 또는 유효한 숫자인지 확인합니다.
 * 유효한 숫자라면 값이 0 이상 10 미만인지 확인합니다.
 * 유효하지 않은 입력이 발견되면 예외를 발생시킵니다.
 */
void RPN::validateInput(std::string s) {
	if (s.length() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
		return;
	char *ptr = NULL;
	double value = std::strtod(s.c_str(), &ptr);
	if (value == 0.0 && !std::isdigit(s[0])) throw RPN::Error();
	if (*ptr && std::strcmp(ptr, "f")) throw RPN::Error();
	if (value < 0 || value >= 10) throw RPN::Error();
	++this->numberOfValues;
}

bool RPN::isOperator(char op) {
	return (op == '+' || op == '-' || op == '*' || op == '/');
}

double RPN::calculator(double a, double b, char op) {
	if (op == '+') return (a + b);
	if (op == '-') return (a - b);
	if (op == '*') return (a * b);
	if (b == 0) throw RPN::Error();
	return (a / b);
}

/**
 * @brief RPN 표현식을 계산하는 함수
 *
 * 스택에 저장된 RPN 표현식을 순서대로 처리하여 최종 결과를 계산합니다.
 * 연산자가 나오면 스택에서 두 개의 숫자를 꺼내어 계산하고, 그 결과를 다시 스택에 넣습니다.
 * 최종 결과를 출력합니다.
 */
void RPN::calculate() {
	while (!this->splitString.empty()) {
		std::string tmp = this->splitString.top();
		if (isOperator(tmp[0])) {
			if (this->rpn.size() < 2) throw RPN::Error();
			double a, b;
			b = this->rpn.top();
			this->rpn.pop();
			a = this->rpn.top();
			this->rpn.pop();
			this->rpn.push(this->calculator(a, b, tmp[0]));
		} else {
			double value = std::strtod(this->splitString.top().c_str(), NULL);
			this->rpn.push(value);
		}
		this->splitString.pop();
	}
	std::cout << this->rpn.top() << std::endl;
}

void RPN::play() {
	try {
		split();
		calculate();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

const char *RPN::Error::what() const throw() {
	return "Error";
}
