#include "RepoFileCSV.h"
#include <fstream>
#include "Medicament.h"
#include "Angajat.h"

RepoFileCSV::RepoFileCSV() :RepoFile() {

}

RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName) {
	this->loadFromfile();
}

RepoFileCSV::~RepoFileCSV() {

}

void RepoFileCSV::loadFromfile() {
	ifstream f(this->fileName);
	if (f.is_open()) {
		this->emptyRepo();
		string linie;
		string delim = ",";
		while (getline(f, linie)) {
			if (linie.substr(0, 3) == "MED") {
				linie = linie.erase(0, 4);

				int pos = linie.find(delim);
				int id = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				bool reteta;
				pos = linie.find(delim);
				if (linie.substr(0, pos) == "false")
					reteta = false;
				else
					reteta = true;
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nrStoc = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string producator = linie.substr(0, pos);

				Medicament* med = new Medicament(id, nume, reteta, nrStoc, producator);
				this->elemente.push_back(med);
			}
			else if (linie.substr(0, 3) == "ANG") {
				linie = linie.erase(0, 4);

				int pos = linie.find(delim);
				int id = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string email = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int grad = stoi(linie.substr(0, pos));

				Angajat* ang = new Angajat(id, nume, email, grad);
				this->elemente.push_back(ang);
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile() {
	ofstream f(this->fileName);
	if (f.is_open()) {
		for (Entitate* elem : this->elemente) {
			f << elem->toString(",") << endl;
		}
	}
}