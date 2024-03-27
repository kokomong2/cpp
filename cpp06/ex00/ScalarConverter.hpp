#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter {
private:
	char _c;
	int _i;
	float _f;
	double _d;

	bool _impossible;

	std::string _str;
	e_type _type;

public:
	ScalarConverter();
	ScalarConverter(std::string str);
	ScalarConverter(ScalarConverter const & src);
	~ScalarConverter();
	ScalarConverter & operator=(ScalarConverter const & src);

	void convert(void);

	void convertChar();
	void convertInt();
	void convertFloat();
	void convertDouble();
	void printChar() const;
	void printInt() const;
	void printFloat() const;
	void printDouble() const;

	void setType();
	bool isChar() const;
	bool isInt() const;
	bool isFloat() const;
	bool isDouble() const;
	bool isImpossible();
	bool isLiterals() const;

	char getC() const;
	int getI() const;
	float getF() const;
	double getD() const;

	class ImpossibleException: public std::exception {
		virtual const char* what() const throw();
	};

	class NonDisplayableException: public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, ScalarConverter const & src);

#endif
