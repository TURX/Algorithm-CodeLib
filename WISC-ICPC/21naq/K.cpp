#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<unsigned long long> V;
unsigned long long sum = 0;

inline unsigned long long suffix(int index) {
	// sum[index+1 ... M]
	return sum - V[index];
}

inline bool check(unsigned long long q) {
	if (q == 0 || q == sum) return true;
	int preIndex = -1, sufIndex = M;
	// prefix
	for (int i = 0; i <= M; i++) {
		if (V[i] == q) return true;
		if (V[i] > q) {
			preIndex = i;
			break;
		}
	}
	if (preIndex == -1) return false;
	while (V[preIndex] + suffix(sufIndex) > q) {
		preIndex--;
		if (preIndex < 0) return false;
		while (V[preIndex] + suffix(sufIndex) < q) {
			sufIndex--;
			if (sufIndex < 0) return false;
		}
	}
	if (V[preIndex] + suffix(sufIndex) == q) return true;
	return false;
}

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	cin >> M >> N;
	V.push_back(0);
	for (int i = 0; i < M; i++) {
		unsigned long long c;
		cin >> c;
		sum += c;
		V.push_back(sum);
	}
	for (int i = 0; i < N; i++) {
		unsigned long long q;
		cin >> q;
		// cout << q << " ";
		if (check(q)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
