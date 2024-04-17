#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>


struct Task {
	int r;
	int p;
	int q;
	int np;

	Task();
	Task(int a, int b, int c, int d) { r = a; p = b; q = c; np = d; }
};

struct Data {
	std::vector<Task> Tasks; // loaded tasks 
	std::vector<int> Order; // optimal order
	int Cmax; // Cmax for that order
	int n; // number of tasks

	void readData(std::string path);

	void showOrderAndCmax();
};

std::istream& operator >> (std::istream& s, Task& t);



// for heaps
struct {
	bool operator() (Task a, Task b) const { return a.r > b.r; }
} compMinR;

struct {
	bool operator() (Task a, Task b) const { return a.q < b.q; }
} compMaxQ;

// for priority queues
class CmpMinR {
public:
	bool operator() (Task a, Task b) const { return a.r > b.r; }
};
class CmpMaxQ {
public:
	bool operator() (Task a, Task b) const { return a.q < b.q; }
};