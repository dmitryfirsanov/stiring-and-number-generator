#include "Generator.h"

Generator::Generator(int n, int type) : _n(n), _type(type) {}


int Generator::getN() const {
	return _n;
}

int Generator::getType()  const {
	return _type;
}

std::string Generator::Generate()
{
	return std::string();
}

std::string Generator::normalizeDouble(std::string& str) {
	while (str.rfind("0") == str.size() - 1 && getN() != 0) {
		str.erase(str.rfind("0"), 1);
	}

	if (str.find(".") == str.size() - 1) {
		str.erase(str.find("."), 1);
	}

	return str;
};