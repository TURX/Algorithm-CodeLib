#include <iostream>
using namespace std;

int T, K, N;

bool solve(int K, int N) {
	if (N == 0) return true;
	if (K == 1 && N == 1) return true;
	if (K < 2) return false;
	return solve(K - 2, N - 1);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> K >> N;
		if (!solve(K, N)) cout << -1 << endl;
		else {
			int cnt = 0;
			for (int i = 1; i <= K; i++) {
				for (int j = 1; j <= K; j++) {
					if (cnt < N && i % 2 == 1 && j == i) {
						cout << 'R';
						cnt++;
					} else cout << '.';
				}
				cout << endl;
			}
		}
	}
}
