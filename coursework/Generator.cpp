#include "Generator.h"
#include <string>
#include <cmath>
#include <random>

unitGenerator::unitGenerator() : _n(5), _type(0), _method(0) {}

unitGenerator::unitGenerator(int n, int type, int method) {
	_n = n;
	_type = type;
	_method = method;
}

unitGenerator::~unitGenerator() {}

std::string unitGenerator::midSquareMethodInt()
{
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> uni_dist(0, SHRT_MAX);

	auto x0 = uni_dist(gen);
	std::string str = std::to_string(pow(x0, 2));
	trim_middle(str);

	while (str.find("0") == 0) {
		str.erase(0, 1);
	}
	if (str == "") {
		str += "0";
	}

	while (stoi(str) > getN()) {
		str = midSquareMethodInt();
	}

	return str;
}

std::string unitGenerator::midSquareMethodDouble()
{
	return std::string();
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

std::string normalize(std::string &str)
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

std::string trim_middle(std::string &str)
{
	str.erase(str.rfind('.'), str.size() - 1);
	normalize(str);
	int size = ceil(str.size() / 4.0);
	str.erase(0, size);
	str.erase(str.size() - size, size);
	return str;
}
