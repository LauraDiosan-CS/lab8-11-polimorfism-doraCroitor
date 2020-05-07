#include "Medicament.h"

// Constructorul implicit
Medicament::Medicament() :Entitate() {

}

// Constructorul cu parametrii
Medicament::Medicament(int id, string nume, bool reteta, int nrStoc, string producator) : Entitate(id, nume) {
	this->reteta = reteta;
	this->nrStoc = nrStoc;
	this->producator = producator;
}

// Constructorul de copiere
Medicament::Medicament(const Medicament& m) : Entitate(m) {
	this->reteta = m.reteta;
	this->nrStoc = m.nrStoc;
	this->producator = m.producator;
}

// Destructorul
Medicament::~Medicament() {

}


/*
	Desc: Acceseaza daca medicamentul necesita reteta
	In: medicament
	Out: necesita sau nu reteta
*/
bool Medicament::getReteta() {
	return this->reteta;
}


/*
	Desc: Acceseaza nr pe stoc al unui medicament
	In: un medicamen
	Out: nr de stoc
*/
int Medicament::getNrStoc() {
	return this->nrStoc;
}


/*
	Desc: Acceseaza producatorul unui medicament
	In: un medicament
	Out: producatorul medicamentului
*/
string Medicament::getProducator() {
	return this->producator;
}


/*
	Desc: Schimba necesiateta de reteta
	In: noua reteta
	Out: medicamentul cu reteta schimbata
*/
void Medicament::setReteta(bool reteta) {
	this->reteta = reteta;
}


/*
	Desc: Schimba nr de stoc
	In: noul nr
	Out: medicamentul cu nr schimbat
*/
void Medicament::setNrStoc(int nrStoc) {
	this->nrStoc = nrStoc;
}


/*
	Desc: Schimba producatorul
	In: noul producaator
	Out: medicamentul cu producatorul schimbat
*/
void Medicament::setProducator(string producator) {
	this->producator = producator;
}


bool Medicament::operator==(const Medicament& m) {
	return this->Entitate::operator==(m) && this->reteta == m.reteta && this->nrStoc == m.nrStoc && this->producator == m.producator;
}

Medicament& Medicament::operator=(const Medicament& m) {
	this->Entitate::operator=(m);
	this->setReteta(m.reteta);
	this->setNrStoc(m.nrStoc);
	this->setProducator(m.producator);
	return *this;
}

ostream& operator<<(ostream& os, const Medicament& m) {
	os << (Entitate&)m << " " << m.reteta << " " << m.nrStoc << " " << m.producator << endl;
	return os;
}

istream& operator>>(istream& is, Medicament& m) {
	is >> (Entitate&)m >> m.reteta >> m.nrStoc >> m.producator;
	return is;
}

Entitate* Medicament::clone() {
	return new Medicament(this->id, this->nume, this->reteta, this->nrStoc, this->producator);
}

string Medicament::boolToString(bool reteta) {
	if (this->reteta == true)
		return "true";
	else
		return "false";
}

string Medicament::toString(string delim) {
	return "MED" + delim + Entitate::toString(delim) + delim + boolToString(this->reteta) + delim + to_string(this->nrStoc) + delim + this->producator;
}

bool Medicament::stirngToBool(string a) {
	if (a == "false")
		return false;
	else
		return true;
}