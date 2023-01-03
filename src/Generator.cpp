#include "Generator.h"

Generator::Generator(int n, int type) : _n(n), _type(type) {}

int Generator::getN() const {
	return _n;
}

int Generator::getType()  const {
	return _type;
}

std::string normalizeDouble(std::string& str, int decimal) {
	while (str.rfind("0") == str.size() - 1 && decimal != 0) {
		str.erase(str.rfind("0"), 1);
	}

	if (str.find(".") == str.size() - 1) {
		str.erase(str.find("."), 1);
	}

	return str;
};

std::string Generator::Generate()
{
	unsigned long long randomValue;
	std::stringstream ss;
	std::string result;

	switch (getType()) {
	case 0: // int
		randomValue = getRandomValue() % (getN() + 1);
		result = std::to_string(randomValue);
		break;
	case 1: // double
		randomValue = getRandomValue();
		ss << std::fixed << std::setprecision(getN()) << randomValue * pow(10, -int(log10(randomValue) + 1));
		result = ss.str();
		normalizeDouble(result, getN());
		break;
	case 2: // string
		for (int i = 0; i < getN(); i++) {
			std::string symbols = getSymbols();
			int index = getRandomValue() % symbols.size();
			result += symbols[index];
		}
		formatString(result);
		break;
	default:
		break;
	}

	return result;
}

std::string Generator::getSymbols() {

	std::string latinAlphabet("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
	std::string cyrillicAlphabet("AaÁáÂâÃãÄäÅå¨¸ÆæÇçÈèÉéÊêËëÌìÍíÎîÏïÐðÑñÒòÓóÔôÕõÖö×÷ØøÙùÚúÛûÜüÝýÞþßÿ");
	std::string punctuationMarks = "\".,-:;?!";

	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> uni_dist(0, 2);

	int index = uni_dist(gen);
	switch (index) {
	case 0:
		return latinAlphabet;
	case 1: 
		return cyrillicAlphabet;
	case 2:
		return punctuationMarks;
	}
}

void formatString(std::string &buf) {
	for (int i = 0; i < buf.size(); i++) {
		if (buf[i] == '\"' || buf[i] == '.' || buf[i] == ',' || buf[i] == '-' || buf[i] == ':' || buf[i] == ';' || buf[i] == '?' || buf[i] == '!') {
			buf.insert(i + 1, " ");
		}
	}
}