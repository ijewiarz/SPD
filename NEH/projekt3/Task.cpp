#include "Task.h"

using namespace std;

Task::Task() {
	w = np = 0;
}

void Data::showOrderAndNeh() {

	cout << "Optimal neh sum: " << Neh << endl;
	cout << "Order: ";
	for (int i = 0; i < Tasks.size(); ++i) {
		cout << Order[i] + 1 << " ";
	}
	cout << endl;
}

void Data::readData(std::string path) {

	ifstream file;
	int i;
	int m;
	int n;

	file.open(path);
	if (!file.is_open()) {
		cerr << "- Error opening file. Exiting program.\n";
		exit(-1);
	}
	else cerr << "+ File opened.\n";

	file >> n; // tasks number
	file >> m; // machines number

	Tasks.resize(n);
	Order.resize(n);

	for (i = 0; i < n; ++i) {
		Tasks[i].p.resize(m);
		file >> Tasks[i];
		Tasks[i].np = i;
		for (int& x : Tasks[i].p) Tasks[i].w += x;
	}
	
	// default Neh
	Neh = -1;

	// default Order
	for (i = 0; i < n; ++i) Order[i] = i;

	file.close();
}





void Data::Test() {
	for (int i = 0; i < Tasks.size(); ++i) {
		for (int j = 0; j < Tasks[i].p.size(); ++j) {
			cout << Tasks[i].p[j] << " ";
		}
		cout << "W: " << Tasks[i].w;
		cout << endl;
	}
}


std::istream& operator >> (std::istream& s, Task& t) {

	for (int i = 0; i < t.p.size(); ++i) {
		s >> t.p[i];
	}

	return s;
}