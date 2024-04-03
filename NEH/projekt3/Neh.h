#pragma once

#include "Task.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class Neh {

public:

	int countCmax(Data& D, std::vector<int>& Ord);
	void findNeh(Data& D);
	void showVector(std::vector<int> v) {
		for (int i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
	}
};

class CmpMaxW {
public:
	bool operator() (Task a, Task b) const { return a.w < b.w; }
};
