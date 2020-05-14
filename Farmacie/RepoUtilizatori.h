#pragma once
#include "Repository.h"
#include <fstream>
#include <cstddef>
template<class T>

class RepoUtilizatori : public Repository<T> {
private:
	char* fileName;
public:

	RepoUtilizatori() : Repository<T>() {
		this->fileName = NULL;
	};

	~RepoUtilizatori() {
		delete[] this->fileName;
	};

	RepoUtilizatori(const char* fileName)
	{
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();

	};

	void setFileName(const char* fileName) {

		if (this->fileName != NULL) {
			delete[] this->fileName;
		}
		if (fileName != NULL) {
			this->fileName = new char[strlen(fileName) + 1];
			strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		}
		else
			this->fileName = NULL;

	};

	RepoUtilizatori(const RepoUtilizatori& r)
	{

		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();
	}

	void loadFromFile() {

		if (this->fileName != NULL) {


			ifstream f(this->fileName);

			T elem;

			while (f >> elem) {

				Repository<T>::addElem(elem);

			}
			f.close();
		}
		else
			Repository<T>::clear();
	};

	void saveToFile() {

		if (this->fileName != NULL) {

			ofstream f(this->fileName);
			int n = Repository<T>::getSize();
			for (int i = 0; i < n; i++)
				f << Repository<T>::getElem(i);

			f.close();
		}
	};


	void addElem(T p) {

		Repository<T>::addElem(p);
		this->saveToFile();
	};


	int getSize() {
		return Repository<T>::getSize();
	}


	void stergere(T c) {
		Repository<T>::stergere(c);
	}


	void update(T& c1, T& c2) {
		Repository<T>::update(c1, c2);
	}


	void setNumberAtPos(int i, int newNumber) {
		Repository<T>::setNumar(i, newNumber);
	};


	vector<T> getAll() {
		return Repository<T>::getAll();
	};

	RepoUtilizatori<T>& operator=(const RepoUtilizatori<T>& repo)
	{
		this->setFileName(repo.fileName);
		this->loadFromFile();

		return *this;

	}

};