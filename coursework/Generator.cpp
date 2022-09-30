#include "Generator.h"

unitGenerator::unitGenerator() : _n(5), _type(0), _method(0) {}

unitGenerator::unitGenerator(size_t n, int type, int method) {
	_n = n;
	_type = type;
	_method = method;
}

unitGenerator::~unitGenerator() {}

size_t unitGenerator::getN() {
	return _n;
}

int unitGenerator::getType() {
	return _type;
}

int unitGenerator::getMethod() {
	return _method;
}