#pragma once
#include <Windows.h>
#include "MyForm.h"
using namespace coursework;
ref class unitGenerator
{
private:
    size_t _n;
    int _type;
    int _method;
public:
    unitGenerator();
    unitGenerator(size_t n, int type, int method);
    ~unitGenerator();

    size_t getN();
    int getType();
    int getMethod();
};
// в последующем создать класс arrayGenerator наследуемый unitGenerator;