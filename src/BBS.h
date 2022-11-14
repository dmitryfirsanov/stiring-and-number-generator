#pragma once

#include "Generator.h"
#include <vector>

using namespace coursework;

class BBS : public Generator {
public:
	BBS(int n, int type);

	std::string Generate() override;

	unsigned long long getRandomValue();
};