#pragma once
#include "Entitate.h"
#include <string>

class Medicament : public Entitate {
private:
	bool reteta;
	int nrStoc;
	string producator;
public:
	Medicament();
	Medicament(int id, string nume, bool reteta, int nrStoc, string producator);
	Medicament(const Medicament& m);
	~Medicament();

	Entitate* clone();
	string toString(string delim);
	string boolToString(bool reteta);
	bool stirngToBool(string a);

	bool getReteta();
	int getNrStoc();
	string getProducator();
	void setReteta(bool reteta);
	void setNrStoc(int nrStoc);
	void setProducator(string producator);

	bool operator==(const Medicament& m);
	Medicament& operator=(const Medicament& m);
	friend ostream& operator<<(ostream& os, const Medicament& m);
	friend istream& operator>>(istream& os, Medicament& m);
};
