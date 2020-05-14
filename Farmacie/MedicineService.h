#pragma once
#include "Medicament.h"
#include "Entitate.h"
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include <vector>
#include <string>

class MedicineService {
private:
	RepoFile* repo;
public:
	MedicineService();
	MedicineService(RepoFile*& repo);
	~MedicineService();

	void setRepo(string optiune);
	int getSize();

	void add(Medicament* m);
	void remove(int id);
	void update(Medicament* m1, Medicament *m2);
	vector<Entitate*> search(string search);
	vector<Entitate*> getAll();

};
