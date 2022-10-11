#include "Generator.h"
#include <string>
#include <cmath>
#include <random>
#include <sstream>
#include <iomanip>

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
	std::string result = getRandomValueMidSquare(pow(10, int(log10(getN()) + 2)));

	while (result.find("0") == 0 && result.size() != 1) {
		result.erase(0, 1);
	}

	while (stoull(result) > getN()) {
		result = midSquareMethodInt();
	}
	return result;
}

std::string unitGenerator::midSquareMethodDouble() {
	std::string randomValue = getRandomValueMidSquare(INT_MAX);

	std::stringstream ss;
	ss << std::fixed << std::setprecision(getN()) << stoull(randomValue) * pow(10, -int(log10(stoull(randomValue)) + 1));
	std::string result = ss.str();
	
	normalizeDouble(result);
	
	return result;
}

std::string unitGenerator::midSquareMethodString()
{
	std::string result;

	for (int i = 0; i < getN(); i++) {
		std::string randomValue = getRandomValueMidSquare(pow(10, 4));
		while (stoull(randomValue) > latinAlphabet.size() - 1) {
			randomValue = getRandomValueMidSquare(pow(10, 4));
		}
		result += latinAlphabet[stoi(randomValue)];
	}

	return result;
}

std::string unitGenerator::ParkMillerGenerator()
{
	unsigned randomValue;
	std::string result;
	std::stringstream ss;
	
	switch (getType())
	{
	case 0: // int
		randomValue = getRandomValueParkMiller() % (getN() + 1);
		result = std::to_string(randomValue);
		break;
	case 1: //double
		randomValue = getRandomValueParkMiller();
		ss << std::fixed << std::setprecision(getN()) << randomValue * pow(10, -int(log10(randomValue) + 1));
		result = ss.str();
		normalizeDouble(result);
		break;
	case 2: // string
		for (int i = 0; i < getN(); i++) {
			randomValue = getRandomValueParkMiller() % latinAlphabet.size();
			result += latinAlphabet[randomValue];
		}
		break;
	default:
		break;
	}
	return result;
}


std::string unitGenerator::normalizeMidSquareMethod(std::string &str) {
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

std::string unitGenerator::normalizeDouble(std::string& str) {
	while (str.rfind("0") == str.size() - 1 && getN() != 0) {
		str.erase(str.rfind("0"), 1);
	}

	if (str.find(".") == str.size() - 1) {
		str.erase(str.find("."), 1);
	}

	return str;
};

std::string unitGenerator::trim_middle(std::string &str) {
	normalizeMidSquareMethod(str);
	int size = ceil(str.size() / 4.0);
	str.erase(0, size);
	str.erase(str.size() - size, size);
	return str;
}

std::string unitGenerator::getRandomValueMidSquare(unsigned long long max)
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

unsigned long long unitGenerator::getRandomValueParkMiller()
{
	const int a = 16807;
	const int q = 12773;
	const int r = 2836;
	const unsigned long long m = INT_MAX;

	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<> uni_dist(1, m - 1);

	auto z = uni_dist(gen);
	unsigned long long randomValue;
	((a * z * m) > 0) ? randomValue = a * z * m : randomValue += m;

	return randomValue;
}
