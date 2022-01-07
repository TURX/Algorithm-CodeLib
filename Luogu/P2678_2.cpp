#include <iostream>
using namespace std;

#define MAXN 50003

int L, N, M, D[MAXN];

int binary(int l, int r) {
	int ans = 0;
	int last = 0;
	int mid = (l + r) / 2;
	for (int i = 1; i <= N; i++) {
		if (mid < D[i] - D[i - 1]) {
			ans = binary(mid + 1, r);
		} else {
			ans = binary(l, mid);
		}
	}
}

int main() {
	cin >> L >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
	}
	binary(0, L);
	return 0;
}
