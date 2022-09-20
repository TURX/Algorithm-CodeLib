#include <iostream>
#include <vector>
using namespace std;

struct Interval {
	Interval(int low, int high) {
		this->low = low;
		this->high = high;
	}
	int low, high;
};

void output(vector<Interval> V) {
	for (int i = 0; i < V.size(); i++) {
		if (V[i].low == V[i].high) cout << V[i].low;
		else cout << V[i].low << "-" << V[i].high;
		if (i == V.size() - 2) cout << " and ";
		else if (i < V.size() - 2) cout << ", ";
	}
}

int main() {
	int C, N;
	cin >> C >> N;
	vector<int> V(N);
	vector<Interval> err, corr;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	if (N == 1) {
		err.push_back(Interval(V[0], V[0]));
	} else {
		int lower = -1, upper = -1;
		for (int i = 0; i < N - 1; i++) {
			if (V[i] == V[i + 1] - 1) {
				upper = i + 1;
				if (lower == -1) lower = i;
			} else {
				if (lower == -1) lower = i;
				if (upper == -1) upper = i;
				err.push_back(Interval(V[lower], V[upper]));
				lower = i + 1; upper = i + 1;
			}
		}
		if (lower != -1 && upper != -1) {
			err.push_back(Interval(V[lower], V[upper]));
		}
	}
	if (err.size() == 0) {
		corr.push_back(Interval(1, C));
	} else {
		if (err[0].low != 1) corr.push_back(Interval(1, err[0].low - 1));
		for (int i = 0; i < err.size() - 1; i++) {
			corr.push_back(Interval(err[i].high + 1, err[i + 1].low - 1));
		}
		if (err[err.size() - 1].high != C) corr.push_back(Interval(err[err.size() - 1].high + 1, C));
	}
	cout << "Errors: ";
	output(err);
	cout << endl;
	cout << "Correct: ";
	output(corr);
	cout << endl;
}
