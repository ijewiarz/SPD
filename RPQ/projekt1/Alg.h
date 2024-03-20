#pragma once

#include "Task.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

class Alg {

	std::vector<Data*> AllData;
	int Csum;

public:

	int getCsum() { return Csum; }
	std::vector<Data*>& getAllData() { return AllData; }
	void readData(std::string path);

	int calcTime(Data& data);
	virtual int calcCmax(int ind) { return -1; }
	void calcCsum();

	void showAllData();

	~Alg() {};
};


class BasicOrder : public Alg {

public:
	virtual int calcCmax(int ind) override;
	~BasicOrder() {};
};

class SortR : public Alg {

public:
	virtual int calcCmax(int ind) override;
	~SortR() {};
};

class Schrage : public Alg {
	virtual int calcCmax(int ind) override;
	~Schrage() {};
};


