#include "Alg.h"

using namespace std;

void Alg::readData(std::string path) {

	ifstream file;
	Data* D = new Data;
	int i;

	file.open(path);
	if (!file.is_open()) {
		cerr << "- Error opening file. Exiting program.\n";
		exit(-1);
	} else cerr << "+ File opened.\n";

	file >> D->n;
	D->Tasks.resize(D->n);
	D->Order.resize(D->n);

	// read data from file
	for (i = 0; i < D->n; ++i) {
		file >> D->Tasks[i];
		D->Tasks[i].np = D->Order[i] = i;
	}

	// default Cmax
	D->Cmax = -1;

	AllData.push_back(D);

	file.close();
}

void Alg::calcCsum() {
	Csum = 0;

	for (int i = 0; i < AllData.size(); ++i) {
		Csum += calcCmax(i);
	}
}

void Alg::showAllData() {
	cout << endl;
	for (int i = 0; i < AllData.size(); ++i) {
		cout << "DATA " << i+1 << endl;
		AllData[i]->showOrderAndCmax();
		cout << "----" << endl;
	}
	cout << "Csum: " << Csum << endl;
}

/*
* IMPORTANT: This method is used to determine Cmax for methods BasicOrder and SortR.
* The sorting method used in SortR changes placement in Tasks vector thus calcTime
* doens't operate on vector Order (from struct Data)
*/
int Alg::calcTime(Data& data) {

	int T = 0;
	int Tq = -1;
	int tmp;
	Task CurrentTask; // current task

	for (int i = 0; i < data.n; ++i) {
		//---
		CurrentTask.r = data.Tasks[i].r;
		CurrentTask.p = data.Tasks[i].p;
		CurrentTask.q = data.Tasks[i].q;
		//---
		if (T < CurrentTask.r) T += CurrentTask.r - T;
		T += CurrentTask.p;

		tmp = CurrentTask.q + T;
		if (tmp > Tq) Tq = tmp;

	}
	if (T < Tq) T = Tq;

	return T;
}


int BasicOrder::calcCmax(int ind) {

	getAllData()[ind]->Cmax = calcTime(*getAllData()[ind]);


	return getAllData()[ind]->Cmax;
}

int SortR::calcCmax(int ind) {

	// sorting
	sort(getAllData()[ind]->Tasks.begin(), getAllData()[ind]->Tasks.end(), compMinR);

	// order
	for (int i = 0; i < getAllData()[ind]->n; ++i) getAllData()[ind]->Order[i] = getAllData()[ind]->Tasks[i].np;

	getAllData()[ind]->Cmax = calcTime(*getAllData()[ind]);

	return getAllData()[ind]->Cmax;
}


/* 
* WNIOSEK DO TEGO ¯E JEST INNY WYNIK W DATA2.TXT NI¯ POWINIEN WYJŒÆ : przez implementacje priority_queue,
* sortuj¹c zmienia kolejnoœæ zadañ o tych samych czasach r, a zak³adam, ¿e program testuj¹cy bierze je po kolei
* (sprawdzono manualnie u¿ywaj¹c kalkulatora)
*/
int Schrage::calcCmax(int ind) {

	vector<int>& ord = getAllData()[ind]->Order;
	priority_queue <Task, vector<Task>, CmpMinR> N(getAllData()[ind]->Tasks.begin(), getAllData()[ind]->Tasks.end());
	priority_queue <Task, vector<Task>, CmpMaxQ> G;

	int t = 0;
	int k = 0;
	int cmax = 0;
	
	while (!G.empty() or !N.empty()) { // while available tasks

		while (!N.empty() and N.top().r <= t) { // push all ready tasks to G
			G.push(N.top());
			N.pop();
		}
		if (G.empty()) { // wait for tasks to be ready
			t = N.top().r;
		}
		else { // calculate time
			ord[k] = G.top().np;
			k++;
			t += G.top().p;
			cmax = max(cmax, t + G.top().q);
			G.pop();
		}
	} 
	getAllData()[ind]->Cmax = cmax;
	
	return cmax;
}



