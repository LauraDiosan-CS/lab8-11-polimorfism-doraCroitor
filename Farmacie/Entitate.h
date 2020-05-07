#pragma once
#include <string>
#include <iostream>

using namespace std;

class Entitate {
protected:
	int id;
	string nume;
public:
	Entitate();
	Entitate(int id, string nume);
	Entitate(const Entitate& e);
	~Entitate();

	virtual Entitate* clone();
	virtual string toString(string delim);

	int getId();
	string getNume();
	void setId(int id);
	void setNume(string nume);

	bool operator==(const Entitate& e);
	Entitate& operator=(const Entitate& e);
	friend ostream& operator<<(ostream& os, const Entitate& e);
	friend istream& operator>>(istream& os, Entitate& e);
};
