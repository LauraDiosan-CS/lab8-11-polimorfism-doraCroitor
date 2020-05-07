#include "Login.h"

// Constructorul implicit
Login::Login() {
	this->username.empty();
	this->parola.empty();
}

// Constructorul cu parametrii
Login::Login(string username, string parola) {
	this->username = username;
	this->parola = parola;
}

// Constructorul de copiere
Login::Login(const Login& l) {
	this->username = l.username;
	this->parola = l.parola;
}

// Destructor
Login::~Login() {

}

/*
	Desc: Acceseaza username-ul
	In: un utilizator
	Out: username-ul utilizatorului
*/
string Login::getUsername() {
	return this->username;
}

/*
	Desc: Schimba username-ul unui utilizator
	In: noul username
	Out: user-ul cu username-ul schimbat
*/
void Login::setUsername(string username) {
	this->username = username;
}

/*
	Desc: Acceseaza parola
	In: un utilizator
	Out: parola utilizatorului
*/
string Login::getParola() {
	return this->parola;
}

/*
	Desc: Schimba parola unui utilizator
	In: noua parola
	Out: utilizatorul cu parola schimbata
*/
void Login::setParola(string parola) {
	this->parola = parola;
}

bool Login::operator==(const Login& e) {
	return (this->username == e.username) && (this->parola == e.parola);
}

ostream& operator<<(ostream& os, const Login& e) {
	os << e.username << " " << e.parola;
	return os;
}

istream& operator>>(istream& is, Login& e) {
	is >> e.username >> e.parola;
	return is;
}

string Login::toString(string delim) {
	return "USER" + delim + this->username + delim + this->parola;
}

Login* Login::clone() {
	return new Login(this->username, this->parola);
}