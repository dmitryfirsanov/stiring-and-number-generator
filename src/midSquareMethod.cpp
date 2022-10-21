#include "midSquareMethod.h"

midSquareMethod::midSquareMethod(int n, int type) : Generator(n, type) {}

std::string midSquareMethod::Generate() {
	std::string randomValue;
	std::stringstream ss;
	std::string result;
	std::string latinAlphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";


	switch (getType()) {
	case 0: // int
		randomValue = getRandomValueMidSquare();
		result = std::to_string(stoull(randomValue) % (getN() + 1));
		break;
	case 1: // double
		randomValue = getRandomValueMidSquare();
		ss << std::fixed << std::setprecision(getN()) << stoull(randomValue) * pow(10, -int(log10(stoull(randomValue)) + 1));
		result = ss.str();
		normalizeDouble(result);
		break;
	case 2: // string
		for (int i = 0; i < getN(); i++) {
			std::string randomValue = getRandomValueMidSquare();
			result += latinAlphabet[stoull(randomValue) % latinAlphabet.size()];
		}
		break;
	default:
		break;
	}

	return result;
}

std::string midSquareMethod::getRandomValueMidSquare() {
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<> uni_dist(0, INT_MAX);

	auto x0 = uni_dist(gen);
	unsigned long long squared = pow(x0, 2);
	std::string randomValue = std::to_string(squared);
	trim_middle(randomValue);

	return randomValue;
}

std::string midSquareMethod::trim_middle(std::string& str) {
	normalizeMidSquareMethod(str);
	int size = ceil(str.size() / 4.0);
	str.erase(0, size);
	str.erase(str.size() - size, size);

	return str;
}

std::string midSquareMethod::normalizeMidSquareMethod(std::string& str) {
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