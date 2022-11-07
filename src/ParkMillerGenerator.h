#pragma once

#include "Generator.h"

using namespace coursework;

class ParkMillerGenerator : public Generator {
public:
	ParkMillerGenerator(int n, int type);

	std::string Generate() override;

	unsigned long long getRandomValue();
};