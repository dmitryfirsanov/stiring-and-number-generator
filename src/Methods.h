#pragma once

#include "Generator.h"
using namespace coursework;

class midSquareMethod : public Generator {
public:
	midSquareMethod(int n, int type);

	unsigned long long getRandomValue() override;
	std::string trimMiddle(std::string&);
	std::string normalize(std::string&);
};

class ParkMillerGenerator : public Generator {
public:
	ParkMillerGenerator(int n, int type);

	unsigned long long getRandomValue() override;
};

class BBS : public Generator {
public:
	BBS(int n, int type);

	unsigned long long getRandomValue() override;
};

class FIPS186 : public Generator {
public:
	FIPS186(int n, int type);

	unsigned long long getRandomValue() override;
};