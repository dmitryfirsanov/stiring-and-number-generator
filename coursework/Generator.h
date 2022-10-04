#pragma once
#include <Windows.h>
#include "MyForm.h"
#include <string>
using namespace coursework;
ref class unitGenerator
{
private:
    int _n;
    int _type;
    int _method;
    int _rangeArray;
public:
    unitGenerator();
    unitGenerator(int n, int type, int method);
    ~unitGenerator();

    std::string midSquareMethodInt();

    int getN();
    int getType();
    int getMethod();
};

std::string normalize(std::string &str);

std::string trim_middle(std::string &str);

// в последующем создать класс arrayGenerator наследуемый unitGenerator