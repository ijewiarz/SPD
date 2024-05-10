#pragma once

#include "Task.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

class Schrage {

public:

	static int Schr(Data& D, std::vector<Task>& pi);
	static int SchrPmtn(Data& D);


	static void printVecT(std::vector<Task>& V) {

		for (auto& i : V) {
			std::cout << i.r << " " << i.p << " " << i.q << " " << i.np << ", ";
		}
		std::cout << std::endl;
	}

	static void printVecI(std::vector<int>& V) {

		for (auto& i : V) {
			std::cout << i << ", ";
		}
		std::cout << std::endl;
	}
};