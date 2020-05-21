#include "Service.h"
#include "ValidationException.h"
#include "ValidatorAngajat.h"
#include "ValidatorEntitate.h"
#include "ValidatorMedicament.h"
#include "ReadFromFileException.h"
#include "RepoException.h"


Service::Service() {
	this->repo = 0;
}

Service::Service(RepoFile*& repo) {
	this->repo = repo;
}

Service::~Service() {

}

void Service::setRepo(string optiune) {
	int len = optiune.length();
	string op = optiune.substr(len - 4, 4);
	if (op == ".csv")
		this->repo = new RepoFileCSV(optiune.c_str());
	else
		this->repo = new RepoFileTXT(optiune.c_str());

}

int Service::getSize() {
	return this->repo->getSize();
}

void Service::addMedicament(int id, string nume, bool reteta, int nrStoc, string producator)  {
	Medicament* m = new Medicament(id, nume, reteta, nrStoc, producator);
	//ValidatorMedicament::validate(m);
	this->repo->addElem(m);
}

void Service::addAngajat(int id, string nume, string email, int grad) {
	Angajat* a = new Angajat(id, nume, email, grad);
	this->repo->addElem(a);
}

void Service::sterge(int id, string initial)   {
	int n = this->repo->getSize();
	for (int i = 0; i < n; i++) {
		string aux = this->repo->getAll()[i]->toString(",");
		string aux2 = aux.substr(0, 3);
		if (aux2 == initial && this->repo->getAll()[i]->getId()== id) {
			this->repo->deleteElem(this->repo->getAll()[i]);
			return;
		}
	}
	
}

void Service::updateMedicament(int id, string nouNume, bool nouReteta, int nouNrStoc, string nouProducator)  {
	int n = this->repo->getSize();
	for (int i = 0; i < n; i++) {
		string aux = this->repo->getAll()[i]->toString(",");
		string aux2 = aux.substr(0, 3);
		if (aux2 == "MED" && this->repo->getAll()[i]->getId() == id) {
			
			Medicament* newMed = new Medicament(id, nouNume, nouReteta, nouNrStoc, nouProducator);
			this->repo->updateElem(this->repo->getAll()[i], newMed);
			delete newMed;
			newMed = NULL;
			return;

		}
	}
}

void Service::updateAngajat(int id, string nouNume, string nouEmail, int nouGrad) {
	int n = this->repo->getSize();
	for (int i = 0; i < n; i++) {
		string aux = this->repo->getAll()[i]->toString(",");
		string aux2 = aux.substr(0, 3);
		if (aux2 == "ANG" && this->repo->getAll()[i]->getId() == id) {
			Angajat* newAng = new Angajat(id, nouNume, nouEmail, nouGrad);
			this->repo->updateElem(this->repo->getAll()[i], newAng);
			delete newAng;
			newAng = NULL;
			return;

		}
	}
}
vector<Entitate*> Service::cautareMedicament(string search){
	vector<Entitate*> elemente;
	int n = this->repo->getSize();
	for (int i = 0; i < n; i++) {
		string aux = this->repo->getAll()[i]->toString(",");
		string aux2 = aux.substr(0, 3);
		string name= this->repo->getAll()[i]->getNume();
		if (aux2 == "MED" && name.find(search) != string::npos) {
			elemente.push_back(this->repo->getAll()[i]);
		}
	}
	return elemente;
}


void Service::modificareGrad(int id, int nouGrad, int gradLogat) {
	int n = this->repo->getSize();
	for (int i = 0; i < n; i++) {
		string aux = this->repo->getAll()[i]->toString(",");
		string aux2 = aux.substr(0, 3);
		if (aux2 == "ANG" && this->repo->getAll()[i]->getId() == id ){//&& ((Angajat*)this->repo->getAll()[i])->getGrad() < gradLogat) {
			if (((Angajat*)this->repo->getAll()[i])->getGrad() < gradLogat) {
				Angajat* newAng = new Angajat(id, this->repo->getAll()[i]->getNume(), ((Angajat*)this->repo->getAll()[i])->getEmail(), nouGrad);
				this->repo->updateElem(this->repo->getAll()[i], newAng);
				delete newAng;
				newAng = NULL;
				return;
			}
			else
				throw stringException("Gradul e mai mic!");
			/*Angajat* newAng = new Angajat(id, this->repo->getAll()[i]->getNume(), ((Angajat*)this->repo->getAll()[i])->getEmail(), nouGrad);
			this->repo->updateElem(this->repo->getAll()[i], newAng);
			delete newAng;
			newAng = NULL;
			return;*/

		}
		//else 
			//throw stringException("Gradul tau e mai mic !");
	}
}


vector<Entitate*> Service::viewAll() {
	return this->repo->getAll();
}

vector<Entitate*> Service::allAng() {
	vector<Entitate*> all = this->repo->getAll();
	vector<Entitate*> angajati;
	for (int i = 0; i < all.size(); i++) {
		string aux = all[i]->toString(",");
		string aux2 = aux.substr(0, 3);
		if (aux2 == "ANG") {
			angajati.push_back(all[i]);
		}
	}
	return angajati;
}

vector<Entitate*> Service::allMed() {
	vector<Entitate*> all = this->repo->getAll();
	vector<Entitate*> medicamente;
	for (int i = 0; i < all.size(); i++) {
		string aux = all[i]->toString(",");
		string aux2 = aux.substr(0, 3);
		if (aux2 == "MED") {
			medicamente.push_back(all[i]);
		}
	}
	return medicamente;
}