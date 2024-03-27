#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string str) : _str(str)
{
	this->_c = '\0';
	this->_i = 0;
	this->_f = 0;
	this->_d = 0;
	this->_impossible = false;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	if (this != &src)
		*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	if (this != &src)
		_str = src._str;
	return (*this);
}

void ScalarConverter::setType() {
	if (isChar())
		_type = CHAR;
	else if (isInt())
		_type = INT;
	else if (isFloat())
		_type = FLOAT;
	else if (isDouble())
		_type = DOUBLE;
	else
		_type = UNKNOWN;
}

bool ScalarConverter::isChar() const
{
	return (_str.length() == 1 && !isdigit(_str[0]));
}

bool ScalarConverter::isInt() const
{
	try
	{
		std::stoi(_str);
		return (true);
	}
	catch (std::exception & e)
	{
		return (false);
	}
}

bool ScalarConverter::isFloat() const
{
	try
	{
		std::stof(_str);
		return (true);
	}
	catch (std::exception & e)
	{
		return (false);
	}
}

bool ScalarConverter::isDouble() const
{
	try
	{
		std::stod(_str);
		return (true);
	}
	catch (std::exception & e)
	{
		return (false);
	}
}

bool ScalarConverter::isImpossible()
{
	try
	{
		if ( _type == INT ) {
			_i = std::stoi( _str );
		} else if ( _type == FLOAT ) {
			_f = std::stof( _str );
		} else if ( _type == DOUBLE ) {
			_d = std::stod( _str );
		}
	}
	catch ( std::exception& e )
	{
		_impossible = true;
		return true;
	}
	return false;
}

bool ScalarConverter::isLiterals() const
{
	if (_impossible)
		return true;
	if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
		return true;
	} else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
		return true;
	} else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
		return true;
	}
	return false;
}

void ScalarConverter::convert(void)
{
	setType();
	isImpossible();
	if (_type == CHAR)
		convertChar();
	else if (_type == INT)
		convertInt();
	else if (_type == FLOAT)
		convertFloat();
	else if (_type == DOUBLE)
		convertDouble();
	else
		throw ImpossibleException();
}

void ScalarConverter::convertChar()
{
	char c = _str[0];
	_c = c;
	_i = static_cast< int >( _c );
	_f = static_cast< float >( _c );
	_d = static_cast< double >( _c );
}

void ScalarConverter::convertInt()
{
	int i = std::stoi(_str);
	_c = static_cast< char >( i );
	_i = i;
	_f = static_cast< float >( i );
	_d = static_cast< double >( i );
}

void ScalarConverter::convertFloat()
{
	float f = std::stof(_str);
	_c = static_cast< char >( f );
	_i = static_cast< int >( f );
	_f = f;
	_d = static_cast< double >( f );
}

void ScalarConverter::convertDouble()
{
	double d = std::stod(_str);
	_c = static_cast< char >( d );
	_i = static_cast< int >( d );
	_f = static_cast< float >( d );
	_d = d;
}

void ScalarConverter::printChar() const
{
	if ( this->isLiterals() || ( !std::isprint( _i ) && ( _i >= 127 ) ) ) {
		throw ImpossibleException();
	} else if ( !std::isprint( this->_i ) ) {
		throw NonDisplayableException();
	} else {
		std::cout << "'" << getC() << "'";
	}
	std::cout << std::endl;
}

void ScalarConverter::printInt() const
{
	if ( this->isLiterals() || ( !std::isprint( _i ) && ( _i >= 127 ) ) ) {
		throw ImpossibleException();
	} else {
		std::cout << getI();
	}
	std::cout << std::endl;
}

void ScalarConverter::printFloat() const
{
	if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
		std::cout << "nanf";
	} else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
		std::cout << "+inff";
	} else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
		std::cout << "-inff";
	} else if ( _impossible ) {
		throw ImpossibleException();
	} else {
		if ( _f - static_cast< int > ( _f ) == 0 ) {
			std::cout << _f << ".0f";
		} else {
			std::cout << getF() << "f";
		}
	}
	std::cout << std::endl;
}

void ScalarConverter::printDouble() const
{
	if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
		std::cout << "nan";
	} else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
		std::cout << "+inf";
	} else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
		std::cout << "-inf";
	} else if ( _impossible ) {
		throw ImpossibleException();
	} else {
		if ( _d - static_cast< int > ( _d ) == 0 ) {
			std::cout << _d << ".0";
		} else {
			std::cout << getD() << "f";
		}
	}
	std::cout << std::endl;
}

const char* ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char* ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

std::ostream & operator<<(std::ostream & o, const ScalarConverter &src)
{
	try {
		std::cout << "char: ";
		src.printChar();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "int: ";
		src.printInt();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "float: ";
		src.printFloat();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "double: ";
		src.printDouble();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (o);
}

char ScalarConverter::getC() const
{
	return (_c);
}

int ScalarConverter::getI() const
{
	return (_i);
}

float ScalarConverter::getF() const
{
	return (_f);
}

double ScalarConverter::getD() const
{
	return (_d);
}
