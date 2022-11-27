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
			std::string symbols = getSymbols();
			int index = getRandomValue() % symbols.size();
			result += symbols[index];
		}
		break;
	default:
		break;
	}

	return result;
}

unsigned long long BBS::getRandomValue() {
	std::vector<int> numbers(10000);
	std::vector<int> primeNumbers;

	for (int i = 0; i < numbers.size(); i++) {
		numbers[i] = i;
	}

	for (int i = 2; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			if (numbers[j] == 0) continue;
			if (j % i == 0) {
				numbers[j] = 0;
				continue;
			}
		}
		if (i * i > numbers.size()) break; // <== ÎÏÒÈÌÈÇÀÖÈß
	}

	for (int i : numbers) {
		if (numbers[i] != 0 && numbers[i] != 1) {
			primeNumbers.push_back(numbers[i]);
		}
	}

	numbers.clear();
	numbers.shrink_to_fit();

	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> uni_dist_forPrime(0, primeNumbers.size() - 1);

	unsigned long long index = uni_dist_forPrime(gen);

	while (primeNumbers[index] % 4 != 3) {
		index = uni_dist_forPrime(gen);
	}
	auto p = primeNumbers[index];

	while (primeNumbers[index] % 4 != 3 && p == primeNumbers[index]) {
		index = uni_dist_forPrime(gen);
	}
	auto q = primeNumbers[index];

	primeNumbers.clear();
	primeNumbers.shrink_to_fit();

	auto M = p * q;

	std::uniform_int_distribution<int> uni_dist(0, INT_MAX);
	auto x = uni_dist(gen);

	while (x % p == 0 && x % q == 0) {
		x = uni_dist(gen);
	}

	unsigned long long randomValue = unsigned long long(pow(x, 2)) % M;
	return randomValue;
}
