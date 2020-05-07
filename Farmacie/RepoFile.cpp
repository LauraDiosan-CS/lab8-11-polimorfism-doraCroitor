#include "RepoFile.h"

RepoFile::RepoFile(string fileName) {
	this->fileName = fileName;
}

void RepoFile::setFileName(string fileName) {
	this->fileName = fileName;
}

vector<Entitate*> RepoFile::getAll() {
	return this->elemente;
}

int RepoFile::getSize() {
	return this->elemente.size();
}

Entitate* RepoFile::getEntitate(int pos) {
	if (pos >= 0 && pos < this->getSize()) {
		return this->elemente[pos]->clone();
	}
	return new Entitate();
}

void RepoFile::addElem(Entitate* e) {
	this->elemente.push_back(e->clone()); 
	this->saveToFile();
}

void RepoFile::updateElem(Entitate* eVechi, Entitate* eNou) {
	for (int i = 0; i < this->elemente.size(); i++) {
		if (this->getEntitate(i)->toString(",") == eVechi->toString(",")) { 
			delete this->elemente[i];
			this->elemente[i] = eNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteElem(Entitate* e) {
	for (int i = 0; i < this->elemente.size(); i++) {
		if ((*(this->elemente.begin() + i))->toString(",")== e->toString(",")) {  
			delete this->elemente[i];
			this->elemente.erase(this->elemente.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::emptyRepo() {
	for (int i = 0; i < this->getSize(); i++) {
		delete this->elemente[i];
	}
	this->elemente.clear();
}