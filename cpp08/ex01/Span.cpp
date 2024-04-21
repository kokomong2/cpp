#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span( unsigned int n ) : _size(0) {
	_vec.reserve(n);
	this->_size = n;
}

Span::Span( const Span& rhs ) : _size(rhs._size), _vec(rhs._vec) {}

Span& Span::operator=( const Span& rhs ) {
	if ( this != &rhs ) {
		_size = rhs._size;
		std::vector<int>().swap(_vec);
		_vec.reserve(_size);
		for ( unsigned int i( 0 ); i < _size; i++ )
			_vec.push_back(rhs._vec[i]);
	}
	return *this;
}

Span::~Span( void ) {
	std::vector<int>().swap(_vec);
}

void Span::addNumber( int n ) {
	if (this->_size == this->_vec.size())
		throw FullArrayException();
	_vec.push_back(n);
}

void Span::addRandomNumbers(int cnt, int min, int max) {
	if ( cnt + this->_vec.size() > _size )
		throw FullArrayException();
	for ( int i( 0 ); i < cnt; i++ )
		_vec.push_back(rand() % (max - min) + min);
	for (int i = 0; i < 100; ++i) {
		std::cout << _vec[i] << " ";
	}
}

int Span::shortestSpan( void ) {
	if ( _size < 2 )
		throw NotEnoughNumbersException();
	std::vector<int> temp_vec = this->_vec;
	std::sort(temp_vec.begin(), temp_vec.end());
	int min_diff = 2147483647;
	for(size_t i = 0; i < temp_vec.size() - 1; i++)
	{
		int diff = temp_vec[i + 1] - temp_vec[i];
		if (diff < min_diff)
			min_diff = diff;
	}
	return (min_diff);
}

int Span::longestSpan( void ) {
	if ( _size < 2 )
		throw NotEnoughNumbersException();
	return (*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end()) );
}

void test10000( void ) {
	Span span = Span(10000);
	span.addRandomNumbers(10000, 0, 10000);
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;;
}

