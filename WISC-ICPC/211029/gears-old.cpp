#include <iostream>
using namespace std;

int cases, N;
long long A[501], M[501];

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if (!b) { x = 1, y = 0; return a; }
	long long d = exgcd(b, a % b, x, y);
	long long z = x; x = y; y = z - y * (a / b);
	return d;
}

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	cin >> cases;
	while (cases--) {
		cin >> N;
		long long multi = 1, ans = 0;
		for (int i = 0; i < N; i++) {
			cin >> M[i] >> A[i]; // x === A[i] (mod M[i])
			A[i] = M[i] - A[i] - 1;
			// ai=M, the i-th gear has ai teeth numbered counter-clockwise from 0 to ai−1
			// M-bi-1=A, the i-th wheel has the tooth bi next to its red mark
			if (M[i] == 0) {
				cout << "Impossible" << endl;
				return 0;
			}
			multi *= M[i];
		}
		for (int i = 0; i < N; i++) {
			long long mod = multi / M[i], t, y;
			exgcd(mod, M[i], t, y); // x * (mod) mod B[i] === 1, t是同余方程的解
			ans = (ans + mod * A[i] * t) % multi;
		}
		cout << (ans + multi) % multi << endl;
	}
}
