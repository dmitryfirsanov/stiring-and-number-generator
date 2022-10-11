#pragma once
#include <Windows.h>
#include "MyForm.h"
#include <string>
using namespace coursework;
class unitGenerator
{
private:
    int _n;
    int _type;
    int _method;
public:
    unitGenerator();
    unitGenerator(int n, int type, int method);
    ~unitGenerator();

    int getN();
    int getType();
    int getMethod();

    std::string midSquareMethod();
    std::string midSquareMethodDouble();
    std::string midSquareMethodString();
};

std::string normalize(std::string &);
std::string trim_middle(std::string &);
std::string getRandomValue(unsigned long long);

// в последующем создать класс arrayGenerator наследуемый unitGenerator