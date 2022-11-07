#include "BBS.h"

BBS::BBS(int n, int type) : Generator(n, type) {}

std::string BBS::Generate() {
	unsigned long long randomValue;
	std::stringstream ss;
	std::string result;
	std::string latinAlphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

	switch (getType()) {
	case 0: // int
		randomValue = getRandomValue() % (getN() + 1);
		result = std::to_string(randomValue);
		break;
	case 1: //double
		randomValue = getRandomValue();
		ss << std::fixed << std::setprecision(getN()) << randomValue * pow(10, -int(log10(randomValue) + 1));
		result = ss.str();
		normalizeDouble(result);
		break;
	case 2: // string
		for (int i = 0; i < getN(); i++) {
			randomValue = getRandomValue() % latinAlphabet.size();
			result += latinAlphabet[randomValue];
		}
		break;
	default:
		break;
	}

	return result;
}

unsigned long long BBS::getRandomValue() {
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> uni_dist(0, 100000);
	
	auto p = 4 * uni_dist(gen) + 3;
	auto q = 4 * uni_dist(gen) + 3;

	while (isPrime(p) != true) {
		p = 4 * uni_dist(gen) + 3;
	}

	while (isPrime(q) != true && p != q) {
		q = 4 * uni_dist(gen) + 3;
	}

	auto n = p * q;

	auto x = uni_dist(gen);

	while (x % p == 0 && x % q == 0) {
		x = uni_dist(gen);
	}
	
	unsigned long long randomValue = unsigned long long(pow(x, 2)) % n;
	return randomValue;
}

bool BBS::isPrime(unsigned long long number) {
	if (number <= 1)
		return false;
	if (number % 2 == 0 && number > 2)
		return false;
	for (int i = 3; i < number / 2; i += 2) {
		if (number % i == 0)
			return false;
	}
	return true;
}


