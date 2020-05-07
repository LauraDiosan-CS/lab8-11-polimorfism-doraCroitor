#pragma once
#include "Entitate.h"
#include <string>

class Angajat : public Entitate {
private:
	string email;
	int grad;
public:
	Angajat();
	Angajat(int id, string nume, string email, int grad);
	Angajat(const Angajat& a);
	~Angajat();

	Entitate* clone();
	string toString(string delim);

	string getEmail();
	int getGrad();
	void setEmail(string email);
	void setGrad(int grad);

	bool operator==(const Angajat& a);
	Angajat& operator=(const Angajat& a);
	friend ostream& operator<<(ostream& os, const Angajat& a);
	friend istream& operator>>(istream& os, Angajat& a);
};
