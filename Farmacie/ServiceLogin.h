#pragma once
#include <string>
#include "Login.h"
#include "RepoUtilizatori.h"

class ServiceLogin {
private:
	RepoUtilizatori<Login> repoUtilizatori;
public:
	ServiceLogin();
	ServiceLogin(const RepoUtilizatori<Login>& repoUtilizatori);
	ServiceLogin(const ServiceLogin& serviceUtilizatori);

	void addUtilizator(string username, string parola);
	bool existaUtilizator(string username, string parola);
	bool readLogin(string username, string parola);
	vector<Login> getAll();
	int getSize();

	ServiceLogin& operator=(const ServiceLogin& serviceUtilizatori);
};
