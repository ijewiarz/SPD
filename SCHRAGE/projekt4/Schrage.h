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

	int SchrPrioQueue(Data& D);
	int SchrHeap(Data& D);
	int SchrpmtnHeap(Data& D);


	void printVec(std::vector<Task>& V) {

		for (auto& i : V) {
			std::cout << i.r << " " << i.p << " " << i.q << " " << i.np << ", ";
		}
		std::cout << std::endl;
	}
};