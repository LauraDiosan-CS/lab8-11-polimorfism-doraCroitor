#include "MedicineService.h"

MedicineService::MedicineService() {

}

MedicineService::MedicineService(RepoFile*& repo) {
	this->repo = repo;
}

MedicineService::~MedicineService() {

}

void MedicineService::setRepo(string optiune) {
	int len = optiune.length();
	string op = optiune.substr(len - 4, 4);
	if (op == ".csv")
		this->repo = new RepoFileCSV(optiune.c_str());
	else
		this->repo = new RepoFileTXT(optiune.c_str());

}

int MedicineService::getSize() {
	return this->repo->getSize();
}

void MedicineService::add(Medicament* m) {
	//Medicament* m1 = new Medicament(m);
	this->repo->addElem(m);
}

void MedicineService::remove(int id) {
	int n = this->repo->getSize();
	for (int i = 0; i < n; i++) {
		//string aux = this->repo->getAll()[i]->toString(",");
		//string aux2 = aux.substr(0, 3);
		if (this->repo->getAll()[i]->getId() == id) {
			this->repo->deleteElem(this->repo->getAll()[i]);
			return;
		}
	}
}

void MedicineService::update(Medicament* m1, Medicament* m2) {
	int n = this->repo->getSize();
	for (int i = 0; i < n; i++) {
		if ( this->repo->getAll()[i]->toString("/") == m1->toString("/")) {

			Medicament* newMed = m2;
			this->repo->updateElem(this->repo->getAll()[i], newMed);
			//delete newMed;
			//newMed = NULL;
			return;

		}
	}
}

vector<Entitate*> MedicineService::search(string search) {
	vector<Entitate*> elemente;
	int n = this->repo->getSize();
	for (int i = 0; i < n; i++) {
		string aux = this->repo->getAll()[i]->toString(",");
		string aux2 = aux.substr(0, 3);
		string name = this->repo->getAll()[i]->getNume();
		if (aux2 == "MED" && name.find(search) != string::npos) {
			elemente.push_back(this->repo->getAll()[i]);
		}
	}
	return elemente;
}

vector<Entitate*> MedicineService::getAll() {
	return this->repo->getAll();
}