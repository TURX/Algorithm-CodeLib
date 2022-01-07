#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int T, N, A[2001], Q, X[100001], K[100001];

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin >> T;
	while (T--) {
		vector<vector<int>> V; // V[step][x]
		vector<int> tempV; // tempV[x]
		int maxSol = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			tempV.push_back(A[i]);
		}
		V.push_back(tempV);
		int maxK = 0;
		cin >> Q;
		for (int i = 0; i < Q; i++) {
			cin >> X[i] >> K[i];
			maxK = max(maxK, K[i]);
		}
		for (int i = 1; i <= maxK; i++) {
			unordered_map<int, int> M;
			for (int j = 0; j < N; j++) {
				M[V[i - 1][j]]++;
			}
			tempV.clear();
			int id = 0;
			for (int j = 0; j < N; j++) {
				if (V[i - 1][j] == M[V[i - 1][j]]) id++;
				tempV.push_back(M[V[i - 1][j]]);
			}
			V.push_back(tempV);
			if (id == N) {
				maxSol = i;
				break;
			}
		}
		if (!maxSol) maxSol = maxK;
		for (int i = 0; i < Q; i++) {
			if (K[i] > maxSol) K[i] = maxSol;
			cout << V[K[i]][X[i] - 1] << endl;
		}
	}
}
