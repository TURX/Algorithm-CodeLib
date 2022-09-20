#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN 100003

int T, N, A[MAXN], cMin, cnt;
unordered_set<int> S;

// find cMin < min (ans) < x, i.e., ceil(n / 2)
int findMin(int x) {
	if (cMin >= x) return -1;
	int m = cMin + 1;
	while (S.count(m)) m++;
	if (m >= x) return -1;
	return m;
}

bool occupyMin(int x) {
	int m = findMin(x);
	if (m == -1 || m > N) return false;
	S.insert(m);
	cMin = m;
	return true;
}

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> A[i];
		sort(A, A + N);
		S.clear();
		cMin = 0;
		cnt = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] <= N) {
				if (S.count(A[i])) S.insert(A[i]);
				else {
					// repeated
					if (!occupyMin(ceil(A[i] / 2.0))) {
						cnt = -1;
						break;
					}
					cnt++;
				}
			} else {
				// exceeds allowance
				if (!occupyMin(ceil(A[i] / 2.0))) {
					cnt = -1;
					break;
				}
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}
