#pragma once 
#include "RepoFile.h"
#include "Entitate.h"
#include "Medicament.h"
#include "Angajat.h"
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include <vector>
#include <string>
#include "Exception.h"

class Service {
private:
	RepoFile* repo;
public:
	Service();
	Service(RepoFile*& repo);
	~Service();

	void setRepo(string optiune);
	int getSize();

	void addMedicament(int id, string nume, bool reteta, int nrStoc, string producator);
	void addAngajat(int id, string nume, string email, int grad);
	void sterge(int id, string initial);
	void updateMedicament(int id, string nouNume, bool nouReteta, int nouNrStoc, string nouProducator);
	void updateAngajat(int id, string nouNume, string nouEmail, int nouGrad);
	vector<Entitate*> cautareMedicament(string search);
	vector<Entitate*> viewAll();
	vector<Entitate*> allAng();
	vector<Entitate*> allMed();
	void modificareGrad(int id, int nouGrad, int gradLogat);
	//void verificareModificare(int id, int nougrad, int gradLogat);


};