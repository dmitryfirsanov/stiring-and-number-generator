#include "Methods.h"

midSquareMethod::midSquareMethod(int n, int type) : Generator(n, type) {}

unsigned long long midSquareMethod::getRandomValue() {
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> uni_dist(0, INT_MAX);

	auto x0 = uni_dist(gen);
	unsigned long long squared = pow(x0, 2);
	std::string randomValue = std::to_string(squared);
	trimMiddle(randomValue);

	return stoull(randomValue);
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

ParkMillerGenerator::ParkMillerGenerator(int n, int type) : Generator(n, type) {}

unsigned long long ParkMillerGenerator::getRandomValue()
{
	const int a = 16807;
	const int q = 12773;
	const int r = 2836;
	const unsigned long long m = INT_MAX;

	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> uni_dist(1, m - 1);

	auto z = uni_dist(gen);
	unsigned long long randomValue;
	((a * z * m) > 0) ? randomValue = a * z * m : randomValue += m;

	return randomValue;
}

BBS::BBS(int n, int type) : Generator(n, type) {}

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
		if (i * i > numbers.size()) break;
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

FIPS186::FIPS186(int n, int type) : Generator(n, type) {}

unsigned long long FIPS186::getRandomValue() {
	const uint64_t A = 0x5DEECE66D;
	const uint64_t C = 0xB;
	const uint64_t M = (1ull << 48) - 1;

	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> uni_dist(0, 1000000);

	auto seed = uni_dist(gen);
	unsigned long long randomValue = (A * seed + C) % M;
	return randomValue;
}
