#include <iostream>
using namespace std;

int T, N;
long long L, R, C;

long long cost(long long mic, long long mac, int miid, int maid) {
	if (miid == maid) return mic;
	else return mic + mac;
}

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		// min, max, min cost, max cost, candidate min, candidate max, candidate min cost, candidate max cost
		long long mi, ma, mic, mac, cmi, cma, cmic, cmac;
		// min id, max id, candidate min id, candidate max id
		int miid, maid, cmiid, cmaid;
		for (int i = 0; i < N; i++) {
			cin >> L >> R >> C;
			if (i == 0) {
				mi = L; mic = C; ma = R; mac = C; miid = i; maid = i;
				cmi = L; cmic = C; cma = R; cmac = C; cmiid = i; cmaid = i;
				cout << C << endl;
				continue;
			}
			if (L < mi) {
				mi = L; mic = C; miid = i;
				cmi = L; cmic = C; cmiid = i;
			}
			if (R > ma) {
				ma = R; mac = C; maid = i;
				cma = R; cmac = C; cmaid = i;
			}
			if (L == mi && R == ma) {
				if (C < cost(mic, mac, miid, maid)) {
					mic = C; mac = C; miid = i; maid = i;
				}
			}
			if (L == mi) {
				if (cmic > C) {
					cmi = L; cmic = C; cmiid = i;
				}
			}
			if (R == ma) {
				if (cmac > C) {
					cma = R; cmac = C; cmaid = i;
				}
			}
			if (mi == cmi && ma == cma) {
				if (cost(cmic, cmac, cmiid, cmaid) < cost(mic, mac, miid, maid)) {
					mic = cmic; mac = cmac; miid = cmiid; maid = cmaid;
				}
			}
			cout << cost(mic, mac, miid, maid) << endl;
		}
	}
}
