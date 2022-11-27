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

std::string Generator::getSymbols() {

	std::string latinAlphabet("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
	std::string cyrillicAlphabet("AaÁáÂâÃãÄäÅå¨¸ÆæÇçÈèÉéÊêËëÌìÍíÎîÏïĞğÑñÒòÓóÔôÕõÖö×÷ØøÙùÚúÛûÜüİıŞşßÿ");
	std::string punctuationMarks = "\".,-:;?!";
	//punctuationMarks += '"';


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