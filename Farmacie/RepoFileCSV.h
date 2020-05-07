#pragma once
#include "RepoFile.h"

class RepoFileCSV : public RepoFile {
public:
	RepoFileCSV();
	RepoFileCSV(string fileName);
	~RepoFileCSV();

	void loadFromfile();
	void saveToFile();
};