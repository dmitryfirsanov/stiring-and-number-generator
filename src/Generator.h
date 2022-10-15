#pragma once
#include <Windows.h>
#include "MyForm.h"
#include <string>
using namespace coursework;
class Generator
{
private:
    int _n;
    int _type;
    int _method;
    const std::string _latinAlphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
public:
    Generator();
    Generator(int n, int type, int method);
    ~Generator();

    int getN();
    int getType();
    int getMethod();

    std::string Generate();

    std::string midSquareMethod(); // сделать класс, будет наследовать основное генератор
    std::string ParkMillerGenerator(); // сделать класс, будет наследовать основное генератор

    std::string normalizeMidSquareMethod(std::string&);  // засунуть в класс MD
    std::string normalizeDouble(std::string&); // оставить в этом классе
    std::string trim_middle(std::string&); // засунуть в класс MD

    std::string getRandomValueMidSquare(); // засунуть в класс MD 
    unsigned long long getRandomValueParkMiller(); // засунуть в класс PM
};