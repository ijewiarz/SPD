#include "Schrage.h"

using namespace std;


/*
* Możliwe różnice w kolejności zadań wynikające z implementacji priority queue
*/
int Schrage::SchrPrioQueue(Data& D) {

	vector<int>& ord = D.Order;
	priority_queue <Task, vector<Task>, CmpMinR> N(D.Tasks.begin(), D.Tasks.end());
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
	D.Cmax = cmax;

	return cmax;
}


int Schrage::SchrHeap(Data& D) {

	vector<int>& ord = D.Order;
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
			ord[k] = G.front().np;
			k++;
			t += G.front().p;
			cmax = max(cmax, t + G.front().q);
			pop_heap(G.begin(), G.end(), compMaxQ);
			G.pop_back();
		}
	}
	D.Cmax = cmax;

	return cmax;
}


int Schrage::SchrpmtnHeap(Data& D) {

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
	D.Cmax = cmax;

	return cmax;
}

