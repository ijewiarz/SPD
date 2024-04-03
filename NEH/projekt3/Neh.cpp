#include "Neh.h"

using namespace std;


int Neh::countCmax(Data& D, vector<int>& Ord) {

	int m = D.Tasks[0].p.size();
	vector<int> T(m);
	for (int x = 0; x < m; ++x) T[x] = 0;

	int tmp;

	for (int i = 0; i < Ord.size(); ++i) {
		tmp = Ord[i];

		T[0] += D.Tasks[tmp].p[0]; // time for first machine

		for (int j = 1; j < m; ++j) { // time for the rest

			if (T[j - 1] > T[j]) {
				T[j] = T[j - 1] + D.Tasks[tmp].p[j];
			}
			else {
				T[j] += D.Tasks[tmp].p[j];
			}
		}
	}

	return T[m - 1];
}

void Neh::findNeh(Data& D) {

	priority_queue <Task, vector<Task>, CmpMaxW> Q(D.Tasks.begin(), D.Tasks.end());
	int tmp;
	vector<int> ord;
	vector<int> opt_ord;
	int Cmax = -1;
	int j;

	for (int i = 0; i < D.Tasks.size(); ++i) {
		// add np to Ord, remove from queue
		tmp = Q.top().np;
		opt_ord.push_back(tmp);
		Q.pop();

		Cmax = countCmax(D, opt_ord);
		ord = opt_ord;

		//showVector(ord); cout << "   " << Cmax << endl;
		
		// find Cmax and optimal order
		for (j = ord.size() - 1; j > 0; --j) {
			swap(ord[j], ord[j - 1]);
			tmp = Cmax;
			Cmax = min(Cmax, countCmax(D, ord));
			if (tmp != Cmax) opt_ord = ord;

			//showVector(ord); cout << "   " << Cmax << endl;
		}
		//cout << endl;
	}

	D.Neh = Cmax;
	D.Order = opt_ord;
}



/*
int Neh::countCmax(Data& D, vector<int>& Ord) {

	int m = D.Tasks[0].p.size();
	vector<int> T(m);
	for (int x = 0; x < m; ++x) T[x] = 0;

	int tmp;

	for (int i = 0; i < Ord.size(); ++i) {
		tmp = Ord[i];

		T[0] += D.Tasks[tmp].p[0]; // time for first machine

		for (int j = 1; j < m; ++j) { // time for the rest

			if (T[j - 1] > T[j]) {
				T[j] = T[j - 1] + D.Tasks[tmp].p[j];
			}
			else {
				T[j] += D.Tasks[tmp].p[j];
			}
		}
	}

	return T[m-1];
}

void Neh::findNeh(Data& D) {

	priority_queue <Task, vector<Task>, CmpMaxW> Q(D.Tasks.begin(), D.Tasks.end());
	int tmp;
	vector<int> ord;
	vector<int> opt_ord;
	int Cmax = -1;
	int j;

	for (int i = 0; i < D.Tasks.size(); ++i) {
		// add np to Ord, remove from queue
		tmp = Q.top().np;
		opt_ord.push_back(tmp);
		Q.pop();

		Cmax = countCmax(D, opt_ord);
		ord = opt_ord;

		showVector(ord); cout << "   " << Cmax << endl;
		// find Cmax and optimal order
		for (j = ord.size()-1; j > 0; --j) {
			swap(ord[j], ord[j - 1]);
			tmp = Cmax;
			Cmax = min(Cmax, countCmax(D, ord));
			if (tmp != Cmax) opt_ord = ord;

			showVector(ord); cout << "   " << Cmax << endl;
		}
		cout << endl;
	}

	D.Neh = Cmax;
	D.Order = opt_ord;
}
*/