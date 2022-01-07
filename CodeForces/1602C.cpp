#include <iostream>
#include <vector>
using namespace std;

int T, N;
unsigned long long A[200001];

bool solve(int K) {
	vector<vector<int>> indexSet;
	for (int i = 1; i <= K; i++) { // num of elements in one set
		vector<int> tempIndicies(K);
		for (int pos = 0; pos < K; pos++) {
			for (int index = 1; index <= N; index++) { //
				tempIndicies[pos] = i;
			}
		}
	}
	return true;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 1; i <= N; i++) {
			if (solve(i)) cout << i << " ";
		}
		cout << endl;
	}
}