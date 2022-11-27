#pragma once

#include <Windows.h>
#include "MyForm.h"
#include <string>
#include <cmath>
#include <random>
#include <sstream>
#include <iomanip>

using namespace coursework;

class Generator {
private:
    int _n;
    int _type;
public:
    Generator(int n, int type);

    int getN() const;
    int getType() const;

    virtual std::string Generate();

    std::string normalizeDouble(std::string&);
    std::string getSymbols();
};