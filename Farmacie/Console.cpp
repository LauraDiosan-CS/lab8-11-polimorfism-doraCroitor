#include "Console.h"
#include <iostream>
using namespace std;

bool Console::handleLogare() {
	stringException exp1 = stringException("Cont invalid");

	bool ok = false;
	string username, parola;

	do {
		cout << "Username: ";
		cin >> username;
		cout << "Parola: ";
		cin >> parola;
		if (this->serviceLogin.existaUtilizator(username, parola) == true) {
			cout << "Logare reusita! " << endl<<endl;
			ok = true;
		}
		else {
			cout << "Logarea nu se poate realiza! Mai incearca!" << endl << endl;
			ok = false;
		}
			
		
	} while (this->serviceLogin.existaUtilizator(username, parola) == false);
	if (ok)
		return true;
	else
		return false;


}



void Console::handleShow() {
	vector<Entitate*> elemente = this->service.viewAll();
	for (vector<Entitate*>::iterator it = elemente.begin(); it != elemente.end(); it++) {
		cout << (*it)->toString(",") << endl;
	}
}

void Console::handleShowAng() {
	vector<Entitate*> elemente = this->service.allAng();
	for (vector<Entitate*>::iterator it = elemente.begin(); it != elemente.end(); it++) {
		cout << (*it)->toString(",") << endl;
	}
}

void Console::handleShowMed() {
	vector<Entitate*> elemente = this->service.allMed();
	for (vector<Entitate*>::iterator it = elemente.begin(); it != elemente.end(); it++) {
		cout << (*it)->toString(",") << endl;
	}
}


void Console::handleAddMedicamente() {
	
	int id;
	int nrStoc;
	string nume;
	string producator;
	string reteta;
	cout << "Id: "; cin >> id;

	cin.ignore();
	cout << "Nume: ";
	getline(cin, nume);
	//cin >> nume;

	cin.ignore();
	cout << "Reteta: "; cin >> reteta;

	cout << "Nr stoc: "; cin >> nrStoc;
	cin.ignore();
	cout << "Producator: ";
	getline(cin, producator);

	bool retetaBool;
	if (reteta == "true")
		retetaBool = true;
	else
		retetaBool = false;

	this->service.addMedicament(id, nume, retetaBool, nrStoc, producator);
	cout << "Medicament adaugat";
	
}



bool Console::setRepo() {
	string repo;
	bool ok = true;
	
	do {
		cout << "Ce fisier doriti sa folositi, TXT sau CSV?: ";
		cin >> repo;
		if (repo == "Farmacie.txt" || repo == "Farmacie.csv") {
			this->service.setRepo(repo);
			ok = true;
		}
		else {
			cout << "Nu e bun fisierul!";
			ok = false;
			
		}
	} while (repo != "Farmacie.txt" && repo != "Farmacie.csv");
	
	if (ok == true)
		return true;
	else return false;
}


void Console::handleCautare() {
	stringException exp = stringException("");

	string search;
	cout << "String-ul dupa care vrei sa cauti medicamente: ";
	cin >> search;
	//vector<Entitate*> elemente = this->service.cautareMedicament(search);
	vector<Entitate*> elemente = this->service.cautareMedicament(search);
	for (vector<Entitate*>::iterator it = elemente.begin(); it != elemente.end(); it++) {
		cout << (*it)->toString(",") << endl;
	}

	
	
}


void Console::handleDeleteMedicamente() {
	int id;
	cout << "Ce id are medicamentul pe care vrei sa il stergi? ";
	cin >> id;
	this->service.sterge(id,"MED");
	cout << "Medicamentl a fost sters";
}


void Console::handleUpdateMedicamente() {
	stringException exp = stringException("");

	int id, nrStoc;
	string nume, producator;
	string reteta;

	cout << "Id: ";
	cin >> id;
	


	cin.ignore();
	cout << "Nume: ";
	getline(cin, nume);
	//cin >> nume;

	cin.ignore();
	cout << "Reteta: "; cin >> reteta;

	cout << "Nr stoc: "; cin >> nrStoc;
	cin.ignore();
	cout << "Producator: ";
	getline(cin, producator);
	//cin >> producator;

	bool retetaBool;
	if (reteta == "true")
		retetaBool = true;
	else
		retetaBool = false;

	
	this->service.updateMedicament(id, nume, retetaBool, nrStoc, producator);
	
	cout << "Medicament modificat! ";
	

}


void Console::handleGrad() {
	stringException exp = stringException("");
	int id, nouGrad, gradLogat;
	cout << "Ce id are angajatul pe care vrei sa il modifici? ";
	cin >> id;
	cout << "Noul grad: ";
	cin >> nouGrad;
	cout << "Ce grad ai tu? ";
	cin >> gradLogat;
	try {
		this->service.modificareGrad(id, nouGrad, gradLogat);
	}
	catch (stringException exp) {
		cout << exp.what();
	}
}

void Console::handleShowUtilizatori() {
	vector<Login> p = this->serviceLogin.getAll();
	int n = p.size();
	for (int i = 0; i < n; i++)
		cout << "Username: " << p[i].getUsername() << " , Paraola: " << p[i].getParola()<<endl;
}



void Console::runConsole() {

	if (this->setRepo() == true) {
		if (this->handleLogare() == true) {
			//this->handleShow();
			cout << endl;
			cout << "***MEDICAMENTE***";
			cout << endl;
			this->handleShowMed();
			cout << endl;
			cout << "***ANGAJATI***";
			cout << endl;
			this->handleShowAng();
			cout << endl;
			//this->setRepo();
			int op;
			while (true) {
				this->meniu();
				cin >> op;
				if (op == 1) {
					this->handleCautare();
					cout << endl;
					//this->handleShow();
					cout << endl;
					cout << "***MEDICAMENTE***";
					cout << endl;
					this->handleShowMed();
					cout << endl;
					cout << "***ANGAJATI***";
					cout << endl;
					this->handleShowAng();
					cout << endl;
					cout << endl;

				}
				else if (op == 2) {
					this->meniu2();
					string op2;
					cin >> op2;
					if (op2 == "a") {
						this->handleAddMedicamente();
						cout << endl;
						//this->handleShow();
						cout << endl;
						cout << "***MEDICAMENTE***";
						cout << endl;
						this->handleShowMed();
						cout << endl;
						cout << endl;

					}
					else if (op2 == "b") {
						this->handleDeleteMedicamente();
						cout << endl;
						//this->handleShow();
						cout << endl;
						cout << "***MEDICAMENTE***";
						cout << endl;
						this->handleShowMed();
						cout << endl;
						cout << endl;

					}
					else if (op2 == "c") {
						this->handleUpdateMedicamente();
						cout << endl;
						//this->handleShow();
						cout << endl;
						cout << "***MEDICAMENTE***";
						cout << endl;
						this->handleShowMed();
						cout << endl;
						cout << endl;

					}
				}
				else if (op == 3) {
					cout << endl;
					cout << "***ANGAJATI***";
					cout << endl;
					this->handleShowAng();
					cout << endl;
					this->handleGrad();
					cout << endl;
					//this->handleShow();
					cout << endl;
					cout << "***MEDICAMENTE***";
					cout << endl;
					this->handleShowMed();
					cout << endl;
					cout << "***ANGAJATI***";
					cout << endl;
					this->handleShowAng();
					cout << endl;
					cout << endl;

				}
				else if (op == 4) {
					cout << endl;
					cout << "***UTILIZATORI*** \n";
					this->handleShowUtilizatori();
					cout << endl;
					//this->handleShow();
					cout << endl;
					cout << "***MEDICAMENTE***";
					cout << endl;
					this->handleShowMed();
					cout << endl;
					cout << "***ANGAJATI***";
					cout << endl;
					this->handleShowAng();
					cout << endl;
					cout << endl;

				}
				else
					if (op == 5) {
						cout << "Esti delogat! Ruleaza iar ca sa te loghezi!";
						return;
					}
			}
		}
	}

}