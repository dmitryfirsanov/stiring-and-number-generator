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

    std::string midSquareMethod(); // ������� �����, ����� ����������� �������� ���������
    std::string ParkMillerGenerator(); // ������� �����, ����� ����������� �������� ���������

    std::string normalizeMidSquareMethod(std::string&);  // �������� � ����� MD
    std::string normalizeDouble(std::string&); // �������� � ���� ������
    std::string trim_middle(std::string&); // �������� � ����� MD

    std::string getRandomValueMidSquare(); // �������� � ����� MD 
    unsigned long long getRandomValueParkMiller(); // �������� � ����� PM
};