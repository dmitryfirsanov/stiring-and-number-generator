#include "midSquareMethod.h"

midSquareMethod::midSquareMethod(int n, int type) : Generator(n, type) {}

std::string midSquareMethod::Generate() {
	std::string randomValue;
	std::stringstream ss;
	std::string result;
	// закинть в конструктор 9 строку через инициализцию
	// шаблоны классов, специализация метода для конкретного типа данных

	switch (getType()) {
	case 0: // int
		randomValue = getRandomValue();
		result = std::to_string(stoull(randomValue) % (getN() + 1));
		break;
	case 1: // double
		randomValue = getRandomValue();
		ss << std::fixed << std::setprecision(getN()) << stoull(randomValue) * pow(10, -int(log10(stoull(randomValue)) + 1));
		result = ss.str();
		normalizeDouble(result);
		break;
	case 2: // string
		for (int i = 0; i < getN(); i++) {
			std::string symbols = getSymbols();
			std::string randomValue = getRandomValue();
			int index = stoull(randomValue) % symbols.size();
			result += symbols[index];
		}
		break;
	default:
		break;
	}

	return result;
}

std::string midSquareMethod::getRandomValue() {
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> uni_dist(0, INT_MAX);

	auto x0 = uni_dist(gen);
	unsigned long long squared = pow(x0, 2);
	std::string randomValue = std::to_string(squared);
	trimMiddle(randomValue);

	return randomValue;
}

std::string midSquareMethod::trimMiddle(std::string& str) {
	normalize(str);
	int size = ceil(str.size() / 4.0);
	str.erase(0, size);
	str.erase(str.size() - size, size);

	return str;
}

std::string midSquareMethod::normalize(std::string& str) {
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

