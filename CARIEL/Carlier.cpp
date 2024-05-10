#include "Carlier.h"

using namespace std;



int Carlier::FindB(Data& D, const vector<Task>& pi, int U) {

	int C = 0;
	int index = 0;
	int TaskNum = 0;
	int Q = 0;
	Task tmpTask;

	for (int i = 0; i < D.n; ++i) {
		tmpTask = pi[i];
		
		if (tmpTask.r > C) C += tmpTask.r - C;
		C += tmpTask.p;

		if (C + tmpTask.q == U) {
			index = i;
			//cout << C << endl;
		}
	}

	return index; //numer zadania w znalezionym rozwi¹zaniu pi
}

int Carlier::FindA(Data& D, const vector<Task>& pi, int U, int b) {

	int C = 0;
	int index = 0;
	int SumP = 0;

	for (int j = 0; j <= b; ++j) {
		SumP += pi[j].p;
	}

	for (int i = 0; i < D.n; ++i) {

		if ( (pi[i].r + SumP + pi[b].q) == U) {
			index = i;
			break;
		}
		SumP -= pi[i].p;
	}

	return index;
}

int Carlier::FindC(Data& D, const std::vector<Task>& pi, int b, int a) {

	int index = -1;
	vector<Task> tmpT;

	for (int i = a; i <= b; ++i) {
		if (pi[i].q < pi[b].q) index = i;
	}

	return index;
}
// LOGI DO PLIKU I PORÓWNAÆ Z PROGRAMEM I ZAPISEM Z PROGRAMU (jakie parametry s¹ w poszczególnych carlierach wywolywane)

void Carlier::Algorythm(Data& D, int UB) {

	int U;
	int LB;
	int a, b, c;
	vector<Task> pi; //szukany wynik
	int tmp, tmpR, tmpQ, tmpP, tmpRc, tmpQc, tmpPc;
	int num;
	int h, hc;
	vector<int> tmpLB;

	U = Schrage::Schr(D, pi);

	//Schrage::printVecT(pi);

	if (U < UB) {
		UB = U;
		D.Cmax = U;
		D.Order = D.TaskNpToVector(pi);
	}
	
	b = FindB(D, pi, U);
	a = FindA(D, pi, U, b);
	c = FindC(D, pi, b, a);
	
	//cout << b << " " << a << " " << c << " U " << U << endl;
	if (c < 0) return;

	auto start = pi.begin();
	start = start + c + 1;
	auto stop = pi.begin();
	stop = stop + b + 1;
	tmpR = (min_element(start, stop, cmpR))->r;
	tmpQ = (min_element(start, stop, cmpQ))->q;
	tmpP = 0;
	for (int i = c + 1; i <= b; ++i) tmpP += pi[i].p;
	
	start = start - 1;
	tmpRc = (min_element(start, stop, cmpR))->r;
	tmpQc = (min_element(start, stop, cmpQ))->q;
	tmpPc = 0;
	for (int i = c; i <= b; ++i) tmpPc += pi[i].p;


	// r switch
	num = pi[c].np;
	tmp = D.Tasks[num].r;
	D.Tasks[num].r = max(pi[c].r, tmpR + tmpP);
	//

	LB = Schrage::SchrPmtn(D);
	h = tmpR + tmpQ + tmpP;
	hc = tmpRc + tmpQc + tmpPc;

	tmpLB.push_back(h);
	tmpLB.push_back(hc);
	tmpLB.push_back(LB);
	LB = *max_element(tmpLB.begin(), tmpLB.end());

	if (LB < UB) {
		Algorythm(D, UB);
	}
	D.Tasks[num].r = tmp;

	tmp = D.Tasks[num].q;
	D.Tasks[num].q = max(pi[c].q, tmpQ + tmpP);
	
	LB = Schrage::SchrPmtn(D);
	tmpLB[2] = LB;
	LB = *max_element(tmpLB.begin(), tmpLB.end());
	if (LB < UB) {
		Algorythm(D, UB);
	}
	D.Tasks[num].q = tmp;


	return;
}