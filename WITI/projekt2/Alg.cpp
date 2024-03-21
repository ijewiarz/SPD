#include "Alg.h"

using namespace std;



int Alg::calcWiti(Data& D, vector<int>& ord) {
	
	int T = 0;
	int Sum = 0;
	int n;
	int penalty; // if <0 no penalty calculated via max function

	for (int i = 0; i < ord.size(); ++i) {
		n = ord[i];
		T += D.Tasks[n].p;
		penalty = (T - D.Tasks[n].t) * D.Tasks[n].w;
		Sum += max(penalty, 0);
	}
	return Sum;
}

int Alg::calcK(Data& D, int ind, int C) {
	
	int K;

	K = D.Tasks[ind].w * (C - D.Tasks[ind].t);
	if (K < 0) K = 0;
	return K;
}

int Alg::calcC(Data& D, vector<int>& B) {
	
	int C = 0;

	for (int i = 0; i < B.size(); ++i) {
		if (B[i] == 1) C += D.Tasks[i].p;
	}
	return C;
}

int Alg::countOnes(vector<int>& B) {
	int counter = 0;
	for (int& i : B) {
		if (i == 1) counter++;
	}
	return counter;
}

int Alg::findNextOne(vector<int>& B, int begin) {
	if (begin >= B.size()) return begin;
	
	for (int i = begin; i < B.size(); ++i) {
		if (B[i] == 1) return i;
	}
	cerr << "- Error: findNextOne() - no 1 found. Program aborted.\n";
	exit(-1);
}

// Returns only WiTi sum
int Alg::dynProg(Data& D, vector<int> B) {
	int n = countOnes(B);
	if (n == 0) return 0; // STOP CONDITION

	int C = calcC(D, B);
	int K = 0;
	int W = INT_MAX; //witi
	int ind = 0;

	for (int i = 0; i < n; ++i) {
		ind = findNextOne(B, ind);
		B[ind] = 0;
		K = calcK(D, ind, C);
		//pd = dynProg()
		W = min(W, dynProg(D, B) + K);
		// if zmiana to switch wektorów w pd
		B[ind] = 1;
		ind++;
	}

	//return pd
	return W;
}

// Returns optimal order, which calculating WiTi is based on 
vector<int> Alg::dynProgOrder(Data& D, vector<int> B) {

	vector<int> v;
	int n = countOnes(B);
	if (n == 0) { // STOP CONDITION
		v.resize(1);
		return v; 
	}

	vector<int> pi;
	int W = INT_MAX; //witi
	int ind = 0;
	int tmp;
	int k;

	for (int i = 0; i < n; ++i) {
		ind = findNextOne(B, ind);
		B[ind] = 0;
		v = dynProgOrder(D, B);
		v[n - 1] = ind; // for calculating witi
		tmp = W;		// save W value
		W = min(W, calcWiti(D, v));
		if (tmp != W) { // if there's lower value save vector
			pi = v;
		}
		B[ind] = 1;
		ind++;
	}

	if (n != B.size()) pi.resize(n + 1); //if it's not the end of counting increase vector by 1
	return pi;
}

void Alg::PD(Data& D) {
	
	vector<int> tmp;

	tmp.resize(D.Tasks.size());
	for (int i = 0; i < tmp.size(); ++i) tmp[i] = 1;

	//cout << D.Tasks.size() << endl;

	D.Order = dynProgOrder(D, tmp);
	//cout << D.Order.size() << endl;
	D.Witi = calcWiti(D, D.Order);
	 
	//D.Witi = dynProg(D, tmp);

}