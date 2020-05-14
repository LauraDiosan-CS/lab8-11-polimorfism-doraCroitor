#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Login {
private:
	string username;
	string parola;
public:
	Login();
	Login(string username, string parola);
	Login(const Login& l);
	~Login();

	Login* clone();
	string toString(string delim);

	string getUsername();
	string getParola();
	void setUsername(string username);
	void setParola(string parola);

	bool operator==(const Login& l);
	//Login& operator=(const Login& l);
	friend ostream& operator<<(ostream& os, const Login& l);
	friend istream& operator>>(istream& os, Login& l);

	void getCSVObj(vector<string> info);
	string getCSVString();
};