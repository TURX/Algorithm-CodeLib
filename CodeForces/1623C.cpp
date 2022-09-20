#include <iostream>
#include <vector>
using namespace std;

bool check(int x, vector<int>& A) {
	vector<int> B(A);
	// A[i], A[i + 1], A[i + 2] ==>
	// A[i] + 2 * a, A[i + 1] + a, A[i + 2] - 3 * a
	for (int i = A.size() - 3; i >= 0; i--) {
		int v = min(B[i + 2] - x, A[i + 2]);
		if (v < 0) return false;
		int u = v / 3;
		B[i + 2] -= u * 3;
		B[i + 1] += u;
		B[i] += u * 2;
	}
	// check A
	for (int i = 0; i < 2; i++) {
		if (B[i] < x) return false;
	}
	return true;
}

int solve(int low, int high, vector<int>& A) {
	if (low == high) return low;
	if (check(high, A)) return high;
	int mid = (low + high) / 2;
	if (mid != low && check(mid, A)) return solve(mid, high, A);
	if (check(low, A)) return solve(low, mid, A);
	return -1;
}

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
		for (int i = 0; i < N; i++) cin >> A[i];
		cout << solve(0, 1e9, A) << endl;
	}
}
