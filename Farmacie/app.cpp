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

	cout << "Totul ok ";
	return 0;
}