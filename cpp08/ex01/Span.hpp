//
// Created by sgo on 2024/04/04.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <ctime>
#include <cstdlib>

class Span {
private:
	unsigned int			_size;
	std::vector<int>		_vec;

public:
	Span( void );
	Span( unsigned int n );
	Span( const Span& rhs );
	Span& operator=( const Span& rhs );
	~Span( void );

	void addNumber( int n );
	void addRandomNumbers(int cnt, int min, int max);
	int shortestSpan( void );
	int longestSpan( void );

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw() { return "No span to find";}
	};
	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw() { return "Index is out of bounds";}
	};
	class FullArrayException : public std::exception {
	public:
		virtual const char* what() const throw() { return "Array is full";}
	};
	class NotEnoughNumbersException : public std::exception {
	public:
		virtual const char* what() const throw() { return "Not enough numbers to find a span";}
	};

};

void test10000( void );

#endif
