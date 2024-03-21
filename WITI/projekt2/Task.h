#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>


struct Task {
	int p;
	int w;
	int t;
	int np;

	Task();
};

struct Data {
	std::vector<Task> Tasks; // loaded tasks 
	std::vector<int> Order; // optimal order
	int Witi; // Witi for that order

	void readData(std::string path);
	void showOrderAndWiti();
};

std::istream& operator >> (std::istream& s, Task& t);