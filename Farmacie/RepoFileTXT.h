#pragma once
#include "RepoFile.h"

class RepoFileTXT : public RepoFile {
public:
	RepoFileTXT();
	RepoFileTXT(string fileName);
	~RepoFileTXT();

	void loadFromfile();
	void saveToFile();
};