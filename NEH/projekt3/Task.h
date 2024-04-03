#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>


struct Task {
	std::vector<int> p;
	int w;
	int np;

	Task();
};

struct Data {
	std::vector<Task> Tasks; // loaded tasks 
	std::vector<int> Order; // optimal order
	int Neh; // Neh for that order

	void readData(std::string path);
	void showOrderAndNeh();
	void Test();
};

std::istream& operator >> (std::istream& s, Task& t);