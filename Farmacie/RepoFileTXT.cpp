#include "RepoFileTXT.h"
#include <fstream>
#include "Medicament.h"
#include "Angajat.h"
#include "Login.h"

RepoFileTXT::RepoFileTXT() :RepoFile() {

}

RepoFileTXT::RepoFileTXT(string fileName) : RepoFile(fileName) {
	this->loadFromfile();
}

RepoFileTXT::~RepoFileTXT() {

}

void RepoFileTXT::loadFromfile() {
	ifstream f(this->fileName);
	if (f.is_open()) {
		this->emptyRepo();
		string linie;
		string delim = "/";
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
				if (linie.substr(0, pos) == "true")
					reteta = true;
				else
					reteta = false;
				//string reteta = linie.substr(0, pos);
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
			/*else if (linie.substr(0, 4) == "USER") {
				linie = linie.erase(0, 5);

				int pos = linie.find(delim);
				string username = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string parola = linie.substr(0, pos);

				Login* user = new Login(username, parola);
				//this->elemente.push_back(user);
			}*/
		}
		f.close();
	}
}

void RepoFileTXT::saveToFile() {
	ofstream f(this->fileName);
	if (f.is_open()) {
		for (Entitate* elem : this->elemente) {
			f << elem->toString("/") << endl;
		}
	}
}