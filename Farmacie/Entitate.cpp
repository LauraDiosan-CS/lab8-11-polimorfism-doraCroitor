#include "Entitate.h"

// Constructorul implicit
Entitate::Entitate() {
	this->id = 0;
	this->nume.empty();
}

// Constructorul cu parametrii
Entitate::Entitate(int id, string nume) {
	this->id = id;
	this->nume = nume;
}

// Constructorul de copiere
Entitate::Entitate(const Entitate& e) {
	this->id = e.id;
	this->nume = e.nume;
}

// Destructorul
Entitate::~Entitate() {

}

Entitate* Entitate::clone() {
	return new Entitate(this->id, this->nume);
}

/*
	Desc: Acceseaza id-ul unei entitati
	In: O entitate
	Out: Id-ul entitatii
*/
int Entitate::getId() {
	return this->id;
}


/*
	Desc: Acceseaza numele unei entitati
	In: O entitate
	Out: Numele entitatii
*/
string Entitate::getNume() {
	return this->nume;
}


/*
	Desc: Schimba id-ul unei entitati
	In: noul id
	Out: entitatea cu id-ul schimbat
*/
void Entitate::setId(int id) {
	this->id = id;
}


/*
	Desc: Schimba numele unei entitati
	In: noul nume
	Out: entitatea cu numele schimbat
*/
void Entitate::setNume(string nume) {
	this->nume = nume;
}


bool Entitate::operator==(const Entitate& e) {
	return (this->id == e.id) && (this->nume == e.nume);
}

Entitate& Entitate::operator=(const Entitate& e) {
	this->setId(e.id);
	this->setNume(e.nume);
	return *this;
}

ostream& operator<<(ostream& os, const Entitate& e) {
	os << e.id << " " << e.nume;
	return os;
}

istream& operator>>(istream& is, Entitate& e) {
	is >> e.id >> e.nume;
	return is;
}

string Entitate::toString(string delim) {
	return to_string(this->id) + delim+ this->nume;
}