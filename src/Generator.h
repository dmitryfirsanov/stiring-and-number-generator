#pragma once

#include <Windows.h>
#include "MyForm.h"
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <random>
#include <vector>
using namespace coursework;

class Generator {
private:
    int _n;
    int _type;
public:
    Generator(int n, int type);

    int getN() const;
    int getType() const;

    virtual unsigned long long getRandomValue() = 0;
    std::string Generate();

    std::string getSymbols();

};

void formatString(std::string& buf);
std::string normalizeDouble(std::string&n, int decimal);