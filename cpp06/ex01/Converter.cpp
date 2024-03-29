#include "Converter.hpp"

Converter *Converter::instance = nullptr;

Converter::Converter() {
}

Converter::Converter(Converter const & src) {
	if (this != &src)
		*this = src;
}


Converter::~Converter() {
}

Converter & Converter::operator=(Converter const & src) {
	if (this != &src)
		instance = src.instance;
	return (*this);
}

Converter *Converter::getInstance() {
	if (!instance)
		instance = new Converter();
	return (instance);
}

Data *Converter::getData(std::string name) {
	data = new Data();
	data->name = name;
	return (data);
}

uintptr_t Converter::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Converter::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
