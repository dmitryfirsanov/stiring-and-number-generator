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
    const std::string _latinAlphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
public:
    unitGenerator();
    unitGenerator(int n, int type, int method);
    ~unitGenerator();

    int getN();
    int getType();
    int getMethod();

    std::string Generate();

    std::string midSquareMethod();
    std::string ParkMillerGenerator();

    std::string normalizeMidSquareMethod(std::string&);
    std::string normalizeDouble(std::string&);
    std::string trim_middle(std::string&);

    std::string getRandomValueMidSquare();
    unsigned long long getRandomValueParkMiller();
};
// в последующем создать класс arrayGenerator наследуемый unitGenerator