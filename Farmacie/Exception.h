#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class stringException :public runtime_error {
private: 
	string message;
public:
	stringException(string msg) :runtime_error(msg), message(msg) {};

	string what() {
		return this->message;
	}
};


class intException :public runtime_error {
private:
	string message;
public:
	intException(string msg) :runtime_error(msg), message(msg) {};

	string what() {
		return this->message;
	}
};