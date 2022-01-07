#include <iostream>
using namespace std;

int T, N;
unsigned long long L, R, C;

unsigned long long cost(unsigned long long mic, unsigned long long mac, int miid, int maid) {
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
		unsigned long long mi, ma, mic, mac;
		int miid, maid;
		for (int i = 0; i < N; i++) {
			cin >> L >> R >> C;
			if (i == 0) {
				mi = L; mic = C;
				ma = R; mac = C;
				miid = i; maid = i;
				cout << C << endl;
				continue;
			}
			if (L < mi) {
				mi = L; mic = C; miid = i;
			}
			if (R > ma) {
				ma = R; mac = C; maid = i;
			}
			if (L == mi && R == ma) {
				if (cost(mic, mac, miid, maid) >= C) {
					mic = C; mac = C; miid = i; maid = i;
				}
			}
			else if (L == mi) {
				if (cost(mic, mac, miid, maid) >= cost(C, mac, i, maid)) {
					mic = C; miid = i;
				}
			}
			else if (R == ma) {
				if (cost(mic, mac, miid, maid) >= cost(mic, C, miid, i)) {
					mac = C; maid = i;
				}
			}
			cout << cost(mic, mac, miid, maid) << endl;
		}
	}
}
