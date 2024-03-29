#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>

struct Data {
	std::string name;
};

class Converter {
private:
	static Converter *instance;
	Converter();
	Converter(Converter const & src);
	~Converter();
	Converter & operator=(Converter const & src);
	Data *data;
public:
	static Converter *getInstance();
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
	Data *getData(std::string name);
};


#endif
