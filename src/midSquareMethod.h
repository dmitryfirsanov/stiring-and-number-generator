#pragma once

#include "Generator.h"

using namespace coursework;

class midSquareMethod : public Generator {
public: 
	midSquareMethod(int n, int type);

	std::string Generate() override;
	
	std::string getRandomValue();
	std::string trimMiddle(std::string&);
	std::string normalize(std::string&);
};