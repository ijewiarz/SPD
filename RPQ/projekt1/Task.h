#pragma once

#include <string>
#include <iostream>
#include <vector>


struct Task {
	int r;
	int p;
	int q;
	int np;

	Task();
};

struct Data {
	std::vector<Task> Tasks; // loaded tasks 
	std::vector<int> Order; // optimal order
	int Cmax; // Cmax for that order
	int n; // number of tasks

	void showOrderAndCmax();
};

std::istream& operator >> (std::istream& s, Task& t);


struct {
	bool operator() (Task a, Task b) const { return a.r < b.r; }
} compMinR;

 // to mo¿e dzia³aæ w priority queue, ale w sort() nie
class CmpMinR {
public:
	bool operator() (Task a, Task b) const { return a.r > b.r; }
};
class CmpMaxQ {
public:
	bool operator() (Task a, Task b) const { return a.q < b.q; }
};