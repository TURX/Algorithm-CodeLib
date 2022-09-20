#include <iostream>
#include <cmath>
using namespace std;

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, K;
		string S;
		cin >> N >> K >> S;
		int cnt = 0;
		for (int i = 1; i <= N / 2; i++)
			if (S[i - 1] != S[N - i])
				cnt++;
		cout << "Case #" << t << ": " << abs(K - cnt) << endl;
	}
}
