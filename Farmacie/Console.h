#pragma once
#include "Service.h"
#include "MedicineService.h"
#include "ServiceLogin.h"
#include "Exception.h"


class Console {
private:
	Service service;
	ServiceLogin serviceLogin;
	//MedicineService medService;
public:
	Console() {};
	~Console() {};
	Console(const Service& s,const ServiceLogin& sl/*, const MedicineService& ms*/) {
		this->service = s;
		this->serviceLogin = sl;
		//this->medService = ms;
	}

	void meniu() {
		cout << "1. Cauata medicament dupa un string \n";
		cout << "2. CRUD medicamente \n";
		cout << "3. Modifica grad acces \n";
		cout << "4. Vezi toti utilizatorii \n";
		cout << "5. Logout. \n";
	}

	void meniu2() {
		cout << "a. Adauga medicament \n";
		cout << "b. Sterge medicament \n";
		cout << "c. Modifica medicament \n";
	}

	bool setRepo();
	bool handleLogare();
	void handleCautare();
	void handleAddMedicamente();
	void handleDeleteMedicamente();
	void handleUpdateMedicamente();
	void handleShow();
	void handleShowAng();
	void handleShowMed();
	void handleGrad();
	void handleShowUtilizatori();

	void runConsole();
	//int getInteger();
};
