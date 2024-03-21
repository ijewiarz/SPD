#pragma once

#include "Task.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Alg {

public:

	int calcWiti(Data& D, std::vector<int>& ord);

	int calcK(Data& D, int ind, int C);
	int calcC(Data& D, std::vector<int>& B);
	int countOnes(std::vector<int>& B);
	int findNextOne(std::vector<int>& B, int begin);

	int dynProg(Data& D, std::vector<int> B); // return olny witi
	std::vector<int> dynProgOrder(Data& D, std::vector<int> B); // returns opt order (witi calculated based on that order)
	void PD(Data&); // main program method

	// for help
	void showVec(std::vector<int>& V) {
		for (int& i : V) std::cout << i << " ";
		std::cout << std::endl;
	}

	~Alg() {};
};



