#include <iostream>
using namespace std;

unsigned int N, A[23], O[23][23];

unsigned int orf(int s, int t) {
	if (!O[s][t]) {
		unsigned int ans = 0;
		for (int i = s; i < t; i++) {
			ans |= A[i];
		}
		O[s][t] = ans;
	}
	return O[s][t];
}

unsigned int xorf(int s, int t) {
	unsigned int ans = A[s];
	if (s < t) {
		for (int i = s + 1; i < t; i++) {
			ans ^= A[i];
		}
	}
	return ans;
}

unsigned int split(int s, int t) {
	if (s == t) return A[s];
	unsigned int ans = UINT32_MAX;
	for (int i = s; i <= t; i++) {
		ans = min(ans, orf(s, i) ^ orf(i, t));
		ans = min(ans, split(s, i) ^ split(i, t));
	}
	return ans;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	split(1, N);
}
