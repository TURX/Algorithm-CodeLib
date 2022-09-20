#include <iostream>
#include <vector>
using namespace std;

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		sort(A.begin(), A.end());
		for (int i = 2; i < N - 1; i++) {
			int u = A[i] / 3;
			A[i] %= 3;
			A[i - 1] += u;
			A[i - 2] += u * 2;
		}
		// last element
		int last_index = N - 1;
		if (N > 3) {
			int v = A[last_index] - A[last_index - 3];
			int u = v / 3;
			A[last_index] -= u * 3;
			A[last_index - 1] += u;
			A[last_index - 2] += u * 2;
		} else {
			// N == 3
		}
	}
}
