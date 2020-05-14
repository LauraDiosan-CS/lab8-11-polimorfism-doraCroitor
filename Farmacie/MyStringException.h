#pragma once
#include <stdexcept>
using namespace std;

class MyStringException :
	public runtime_error {
private:
	string message;
public:
	MyStringException(string msg) : runtime_error(msg), message(msg) {};

	string what() {
		return this->message;
	}
};