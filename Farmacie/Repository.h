#pragma once
#include <vector>
using namespace std;

template<class T>
class Repository {
private:
	vector<T> elemente;

public:

	Repository() {};

	// Adauga o prajitura
	void addElem(T e) {
		this->elemente.push_back(e);

	}

	// Toate elementele
	vector<T> getAll() {
		return this->elemente;
	}

	// Lungimea
	int getSize() {
		return this->elemente.size();
	};


	~Repository() {
		this->elemente.clear();
	}

	// sterge
	void stergere(T p)
	{
		typename vector<T>::iterator it;
		it = find(this->elemente.begin(), this->elemente.end(), p);
		if (!(it == this->elemente.end())) {

			this->elemente.erase(it);
		}
	}

	// modifica p1 cu 22
	void update(T& p1, T& p2) {
		typename vector<T>::iterator it;
		it = find(this->elemente.begin(), this->elemente.end(), p1);
		if (!(it == this->elemente.end())) {

			*it = p2;
		}
	};

	void clear() {
		this->elemente.clear();
	}

	T getElem(int i) {

		return this->elemente[i];

	}

};
