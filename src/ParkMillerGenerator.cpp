#include "ParkMillerGenerator.h"

ParkMillerGenerator::ParkMillerGenerator(int n, int type) : Generator(n, type) {}

std::string ParkMillerGenerator::Generate() {
	unsigned randomValue;
	std::stringstream ss;
	std::string result;
	std::string latinAlphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";


	switch (getType()) {
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

unsigned long long ParkMillerGenerator::getRandomValueParkMiller()
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
