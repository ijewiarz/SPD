#include "Task.h"

using namespace std;

Task::Task() {
	r = p = q = np = 0;
}

void Data::showOrderAndCmax() {
	
	cout << "Cmax: " << Cmax << endl;
	cout << "Order: ";
	for (int i = 0; i < n; ++i) {
		cout << Order[i] + 1 << " ";
	}
	cout << endl;
}

std::istream& operator >> (std::istream& s, Task& t) {

	s >> t.r;
	s >> t.p;
	s >> t.q;

	return s;
}