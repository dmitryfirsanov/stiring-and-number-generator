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

std::string unitGenerator::midSquareMethod()
{
	std::string result;
	switch (getType())
	{
	case 0:
		result = midSquareMethodInt();
		break;
	case 1:
		result = midSquareMethodDouble();
		break;
	case 2:
		result = midSquareMethodString();
		break;
	default:
		break;
	}
	return result;
}

std::string unitGenerator::midSquareMethodInt() {
	std::string result = getRandomValue(pow(10, int(log10(getN()) + 2)));

	while (result.find("0") == 0 && result.size() != 1) {
		result.erase(0, 1);
	}

	while (stoull(result) > getN()) {
		result = midSquareMethodInt();
	}
	return result;
}

std::string unitGenerator::midSquareMethodDouble() {
	std::string radnomValue = getRandomValue(INT_MAX);

	std::stringstream ss;
	ss << std::fixed << std::setprecision(getN()) << stoull(radnomValue) * pow(10, -int(log10(stoull(radnomValue)) + 1));
	std::string result = ss.str();
	
	while (result.rfind("0") == result.size() - 1 && getN() != 0) {
		result.erase(result.rfind("0"), 1);
	}

	if (result.find(".") == result.size() - 1) {
		result.erase(result.find("."), 1);
	}
	
	return result;
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

unsigned long long unitGenerator::ParkMillerGenerator()
{
	const int a = 16807;
	const int q = 12773;
	const int r = 2836;
	const unsigned long long m = INT_MAX;
	
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<> uni_dist(1, m - 1);

	auto z	= uni_dist(gen);
	unsigned long long result;
	((a * z * m) < 0) ? result += m : result = a * z * m;
	
	return result % (getN() + 1);
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
