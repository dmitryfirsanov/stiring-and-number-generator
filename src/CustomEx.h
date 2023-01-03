#pragma once
#include "MyForm.h"
#include <string>
#include <msclr\marshal_cppstd.h>
using namespace coursework;
using namespace msclr::interop;

class CustomEx {
public:
	CustomEx(std::string str) {
		message = str;
	}
	//void setMessage(String^ str);
	String^ getMessage();
private:
	std::string message;
};