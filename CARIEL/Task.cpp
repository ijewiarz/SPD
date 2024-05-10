#include "Task.h"

using namespace std;

Task::Task() {
	r = p = q = np = 0;
}


void Data::readData(std::string path) {

	ifstream file;
	int i;

	file.open(path);
	if (!file.is_open()) {
		cerr << "- Error opening file. Exiting program.\n";
		exit(-1);
	}
	else cerr << "+ File opened.\n";

	file >> n;
	Tasks.resize(n);
	Order.resize(n);
	Cmax = -1;

	// read data from file
	for (i = 0; i < n; ++i) {
		file >> Tasks[i];
		Tasks[i].np = Order[i] = i;
	}

	file.close();
}

void Data::showOrderAndCmax() {

	cout << "Cmax: " << Cmax << endl;
	cout << "Order: ";
	for (int i = 0; i < n; ++i) {
		cout << Order[i] + 1 << " "; //Order[i] + 1 for not 0indexing
	}
	cout << endl;
}

std::vector<int> Data::TaskNpToVector(const std::vector<Task>& T) {
	vector<int> numbers;

	for (Task t : T) {
		numbers.push_back(t.np);
	}

	return numbers;
}



std::istream& operator >> (std::istream& s, Task& t) {

	s >> t.r;
	s >> t.p;
	s >> t.q;

	return s;
}