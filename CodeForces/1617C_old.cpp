/*
1 7
1 2(5)

1 5 4
1 2(3) (N)

sort

*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// <=n | >n

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int A[N];
		for (int i = 0; i < N; i++) cin >> A[i];
		sort(A, A + N);
		unordered_map<int, bool> S;
		for (int i = 0; i < N; i++) {
			if (A[i] <= N) {
				if (!S[A[i]]) S[A[i]] = true;
				else {
					// repeated
					
				}
			} else {
				// exceeds allowance
			}
		}
	}
}
