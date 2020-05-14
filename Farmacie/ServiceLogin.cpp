#include "ServiceLogin.h"

ServiceLogin::ServiceLogin() {

}

ServiceLogin::ServiceLogin(const RepoUtilizatori<Login>& repoUtilizatori) {
	this->repoUtilizatori = repoUtilizatori;
}

ServiceLogin::ServiceLogin(const ServiceLogin& serviceUtilizatori) {
	this->repoUtilizatori = serviceUtilizatori.repoUtilizatori;
}

void ServiceLogin::addUtilizator(string username, string parola) {
	Login u(username, parola);
	repoUtilizatori.addElem(u);
}

vector<Login> ServiceLogin::getAll() {
	return repoUtilizatori.getAll();
}

bool ServiceLogin::existaUtilizator(string username, string parola) {
	int n = this->repoUtilizatori.getSize();
	vector<Login> utilizatori = this->repoUtilizatori.getAll();
	for (int i = 0; i < n; i++) {
		if (utilizatori[i].getUsername() == username && utilizatori[i].getParola() == parola)
			return true;
	}
	return false;

}

int ServiceLogin::getSize() {
	return this->repoUtilizatori.getSize();
}


ServiceLogin& ServiceLogin::operator=(const ServiceLogin& serviceUtilizatroi) {
	this->repoUtilizatori = serviceUtilizatroi.repoUtilizatori;
	return *this;
}
