#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N, A[103], DP[25565];

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	for(int casNum = 0; casNum < T; casNum++) {
        memset(DP, 0, sizeof(DP));
		cin >> N;
        int ans = N;
		for(int t = 1; t <= N; t++) cin >> A[t];
		sort(A + 1, A + N + 1);
        DP[0] = 1;
        for(int i = 1; i <= N; i++) {
            if(DP[A[i]]) {
                ans--;
                continue;
            }
            for(int j = A[i]; j <= A[N]; j++) {
                DP[j] = max(DP[j], DP[j - A[i]]);
            }
        }
		cout << ans << endl;
	}
}