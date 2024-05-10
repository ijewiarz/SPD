#include "Schrage.h"

using namespace std;


int Schrage::Schr(Data& D, vector<Task>& pi) {

	//vector<int>& ord = D.Order;
	vector<Task> N = D.Tasks;
	vector<Task> G;
	int t = 0;
	int k = 0;
	int cmax = 0;

	make_heap(N.begin(), N.end(), compMinR); // making N heap

	while (!G.empty() or !N.empty()) { // while available tasks

		while (!N.empty() and N.front().r <= t) { // push all ready tasks to G
			G.push_back(N.front());
			push_heap(G.begin(), G.end(), compMaxQ);

			pop_heap(N.begin(), N.end(), compMinR);
			N.pop_back();
		}
		if (G.empty()) { // wait for tasks to be ready
			t = N.front().r;
		}
		else { // calculate time
			pi.push_back(G.front());
			t += G.front().p;
			cmax = max(cmax, t + G.front().q);
			pop_heap(G.begin(), G.end(), compMaxQ);
			G.pop_back();
		}
	}
	//D.Cmax = cmax;

	return cmax;
}


int Schrage::SchrPmtn(Data& D) {

	vector<Task> N = D.Tasks;
	vector<Task> G;
	int t = 0;
	int cmax = 0;
	Task l(0, 0, INT_MAX, -1);

	make_heap(N.begin(), N.end(), compMinR); // making N heap
	//printVec(N);

	while (!G.empty() or !N.empty()) { // while available tasks

		while (!N.empty() and N.front().r <= t) { // push all ready tasks to G

			G.push_back(N.front());
			push_heap(G.begin(), G.end(), compMaxQ);

			pop_heap(N.begin(), N.end(), compMinR);
			N.pop_back();

			if (G.front().q > l.q) { // if task with greater q
				l.p = t - G.front().r; // update p value
				t = G.front().r; // move time forward 
				if (l.p > 0) { // if still p time move to G heap
					G.push_back(l);
					push_heap(G.begin(), G.end(), compMaxQ);
				}
			}

		}
		if (G.empty()) { // wait for tasks to be ready
			t = N.front().r;
		}
		else { // calculate time
			l = G.front();
			t += G.front().p;
			cmax = max(cmax, t + G.front().q);
			pop_heap(G.begin(), G.end(), compMaxQ);
			G.pop_back();
		}
	}
	//D.Cmax = cmax;

	return cmax;
}

