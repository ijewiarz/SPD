#include "Task.h"

using namespace std;

Task::Task() {
	p = w = t = np = 0;
}

void Data::showOrderAndWiti() {

	cout << "Optimal witi sum: " << Witi << endl;
	cout << "Order: ";
	for (int i = 0; i < Tasks.size(); ++i) {
		cout << Order[i] + 1 << " ";
	}
	cout << endl;
}

void Data::readData(std::string path) {

	ifstream file;
	int i;
	int n;

	file.open(path);
	if (!file.is_open()) {
		cerr << "- Error opening file. Exiting program.\n";
		exit(-1);
	}
	else cerr << "+ File opened.\n";

	file >> n;
	Tasks.resize(n);
	Order.resize(n);

	// read data from file
	for (i = 0; i < n; ++i) {
		file >> Tasks[i];
		Tasks[i].np = Order[i] = i; // default order 1,2,3,...
	}

	// default Witi
	Witi = -1;

	file.close();
}


std::istream& operator >> (std::istream& s, Task& t) {

	s >> t.p;
	s >> t.w;
	s >> t.t;

	return s;
}