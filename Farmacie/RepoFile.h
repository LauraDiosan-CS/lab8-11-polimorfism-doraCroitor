#pragma once
#include "Entitate.h";
#include <vector>
#include "ValidatorAngajat.h"
#include "ValidatorMedicament.h"

using namespace std;

class RepoFile {
protected:
	vector<Entitate*> elemente;
	string fileName;
public:
	RepoFile() {};
	RepoFile(string fileName);
	~RepoFile() {};
	void setFileName(string fileName);

	vector<Entitate*> getAll();
	int getSize();
	Entitate* getEntitate(int pos);
	void addElem(Entitate* e);
	void updateElem(Entitate* eVechi, Entitate* eNou);
	void deleteElem(Entitate* e);
	int findEntitate(Entitate* e);

	void emptyRepo();

	virtual void loadFromfile() {};
	virtual void saveToFile() {};
};
