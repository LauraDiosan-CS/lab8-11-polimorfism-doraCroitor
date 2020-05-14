#include <iostream>
#include <string>
#include "TestAngajat.h"
#include "TestEntitate.h"
#include "TestMedicament.h"
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include "TestRepoFile.h"
#include "TestLogin.h"
#include "MedicineService.h"
#include "Console.h"
#include"Login.h"
#include "RepoUtilizatori.h"
#include "TestService.h"

using namespace std;

int main() {
	TestEntitate testEntitate;
	testEntitate.testAll();

	TestMedicament testMedicament;
	testMedicament.testAll();

	TestAngajat testAngajat;
	testAngajat.testAll();

	TestLogin testLogin;
	testLogin.testAll();

	TestRepoFile testRepoFile;
	testRepoFile.testAll();

	TestService testService;
	testService.testAll();


	RepoUtilizatori<Login> repo("Utilizatori.txt");
	RepoFile repoFile;
	RepoFileCSV repoCSV("Farmacie.csv");
	RepoFileTXT repoTXT("Farmacie.txt");
	ServiceLogin s(repo);
	Service service;
	MedicineService medService;
	Console console(service, s, medService);
	console.runConsole();

	//cout << "Totul ok ";
	return 0;
}