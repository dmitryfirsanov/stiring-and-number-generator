#include "Generator.h"
#include <cstdlib>
#include <time.h>
#include <string>
#include <cmath>

unitGenerator::unitGenerator() : _n(5), _type(0), _method(0) {}

unitGenerator::unitGenerator(int n, int type, int method) {
	_n = n;
	_type = type;
	_method = method;
}

unitGenerator::~unitGenerator() {}

std::string unitGenerator::midSquareMethodInt()
{
	srand(time(NULL));
	int randX0 = rand() % (getN() + 1);
	std::string str = std::to_string(pow(randX0, 2));
	str.erase(str.rfind('.'), str.size() - 1);
	str = normalize(str);
	int size = ceil(str.size() / 4.0);
	str.erase(0, size);
	str.erase(str.size() - size, size);
	return str;
}

int unitGenerator::getN() {
	return _n;
}

int unitGenerator::getType() {
	return _type;
}

int unitGenerator::getMethod() {
	return _method;
}

std::string normalize(std::string str)
{
	if (str.size() < 4) {
		while (str.size() != 4) {
			str.insert(0, "0");
		}
	}
	else if (str.size() % 2 == 1) {
		str.insert(0, "0");
	}
	return str;
}
