#include "Span.hpp"

Span::Span() : _n(0), _size(0) {}

Span::Span( unsigned int n ) : _n(n), _size(0) {
	_arr = new int[n];
}

Span::Span( const Span& rhs ) : _n(rhs._n), _size(rhs._size), _arr(rhs._arr) {}

Span& Span::operator=( const Span& rhs ) {
	if ( this != &rhs ) {
		_n = rhs._n;
		_size = rhs._size;
		delete [] _arr;
		_arr = new int[_n];
		for ( unsigned int i( 0 ); i < _size; i++ )
			_arr[i] = rhs._arr[i];
	}
	return *this;
}

Span::~Span( void ) {
	delete [] _arr;
}

void Span::addNumber( int n ) {
	if ( _size == _n )
		throw FullArrayException();
	_arr[_size++] = n;
}

int Span::shortestSpan( void ) {
	if ( _size < 2 )
		throw NotEnoughNumbersException();
	std::sort(_arr, _arr + _size);
	int min = _arr[1] - _arr[0];
	for ( unsigned int i( 2 ); i < _size; i++ ) {
		if ( _arr[i] - _arr[i - 1] < min )
			min = _arr[i] - _arr[i - 1];
	}
	return min;
}

int Span::longestSpan( void ) {
	if ( _size < 2 )
		throw NotEnoughNumbersException();
	return (*std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end()) );
}

