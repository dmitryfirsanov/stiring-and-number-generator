#pragma once

#include "Generator.h"

using namespace coursework;

class BBS : public Generator {
public:
	BBS(int n, int type);

	std::string Generate() override;

	unsigned long long getRandomValue();
	bool isPrime(unsigned long long number);
};