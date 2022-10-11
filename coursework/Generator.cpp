#include "Generator.h"
#include <string>
#include <cmath>
#include <random>
#include <sstream>
#include <iomanip>
#include <regex>

unitGenerator::unitGenerator() : _n(5), _type(0), _method(0) {}

unitGenerator::unitGenerator(int n, int type, int method) {
	_n = n;
	_type = type;
	_method = method;
}

unitGenerator::~unitGenerator() {}

int unitGenerator::getN() {
	return _n;
}

int unitGenerator::getType() {
	return _type;
}

int unitGenerator::getMethod() {
	return _method;
}

std::string unitGenerator::midSquareMethod() {
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<> uni_dist(0, pow(10, int (log10(getN()) + 2)));

	auto x0 = uni_dist(gen);
	unsigned long long squared = pow(x0, 2);
	std::string str = std::to_string(squared);
	trim_middle(str);

	while (str.find("0") == 0 && str.size() != 1) {
		str.erase(0, 1);
	}

	while (stoull(str) > getN()) {
		str = midSquareMethod();
	}
	return str;
}

std::string unitGenerator::midSquareMethodDouble() {
	std::random_device rd;
	std::mt19937_64 gen(rd()); 
	std::uniform_int_distribution<> uni_dist(0, INT_MAX);

	auto x0 = uni_dist(gen);
	unsigned long long squared = pow(x0, 2);
	std::string str = std::to_string(squared);
	trim_middle(str);

	std::stringstream ss;
	ss << std::fixed << std::setprecision(getN()) << stoull(str) * pow(10, -int(log10(stoull(str)) + 1));
	str = ss.str();
	
	while (str.rfind("0") == str.size() - 1 && getN() != 0) {
		str.erase(str.rfind("0"), 1);
	}

	if (str.find(".") == str.size() - 1) {
		str.erase(str.find("."), 1);
	}
	
	return str;
}

std::string unitGenerator::midSquareMethodString()
{
	std::string latinAlphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	std::string result;

	for (int i = 0; i < getN(); i++) {
		std::string randomValue = getRandomValue(pow(10, 4));
		while (stoull(randomValue) > latinAlphabet.size() - 1) {
			randomValue = getRandomValue(pow(10, 4));
		}
		result += latinAlphabet[stoi(randomValue)];
	}

	return result;
}


std::string normalize(std::string &str) {
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

std::string trim_middle(std::string &str) {
	normalize(str);
	int size = ceil(str.size() / 4.0);
	str.erase(0, size);
	str.erase(str.size() - size, size);
	return str;
}

std::string getRandomValue(unsigned long long max)
{
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<> uni_dist(0, max);

	auto x0 = uni_dist(gen);
	unsigned long long squared = pow(x0, 2);
	std::string randomValue = std::to_string(squared);
	trim_middle(randomValue);
	return randomValue;
}
