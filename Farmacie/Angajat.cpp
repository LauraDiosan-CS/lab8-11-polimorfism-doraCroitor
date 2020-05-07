#include "Angajat.h"

// Constructorul  implicit
Angajat::Angajat() : Entitate() {

}

// Constructorul cu parametrii
Angajat::Angajat(int id, string nume, string email, int grad) : Entitate(id, nume) {
	this->email = email;
	this->grad = grad;
}

// Constructorul de copiere
Angajat::Angajat(const Angajat& a) :Entitate(a) {
	this->email = a.email;
	this->grad = a.grad;
}

// Destructorul
Angajat::~Angajat() {

}


/*
	Desc: Acceseaza emailul unui angajat
	In: angajat
	Out: emailul angajatului
*/
string Angajat::getEmail() {
	return this->email;
}


/*
	Desc: Acceseaza gradul de acces al unui angajat
	In: angajat
	Out: gradul de acces al angajatului
*/
int Angajat::getGrad() {
	return this->grad;
}


/*
	Desc: Schimba emailul unui angajat
	In: email
	Out: emailul schimbat 
*/
void Angajat::setEmail(string email) {
	this->email = email;
}


/*
	Desc: Schimba gradul unui angajat
	In: noul grad
	Out: gradul schimbat
*/
void Angajat::setGrad(int grad) {
	this->grad = grad;
}

bool Angajat::operator==(const Angajat& a) {
	return this->Entitate::operator==(a) && this->email == a.email && this->grad == a.grad ;
}

Angajat& Angajat::operator=(const Angajat& a) {
	this->Entitate::operator=(a);
	this->setEmail(a.email);
	this->setGrad(a.grad);
	return *this;
}

ostream& operator<<(ostream& os, const Angajat& a) {
	os << (Entitate&)a << " " << a.email << " " << a.grad << endl;
	return os;
}

istream& operator>>(istream& is, Angajat& a) {
	is >> (Entitate&)a >> a.email >> a.grad;
	return is;
}

Entitate* Angajat::clone() {
	return new Angajat(this->id, this->nume, this->email, this->grad);
}

string Angajat::toString(string delim) {
	return "ANG" + delim + Entitate::toString(delim) + delim + this->email + delim + to_string(this->grad);
}