#pragma once

#include "Generator.h"

using namespace coursework;

class midSquareMethod : public Generator {
public: 
	midSquareMethod(int n, int type);

	std::string Generate() override;
	
	std::string getRandomValueMidSquare();
	std::string trim_middle(std::string&);
	std::string normalizeMidSquareMethod(std::string&);
};