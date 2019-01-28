#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 201

int N, A[MAXN], DP[MAXN][MAXN], SUM[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 1; t <= N; t++) cin >> A[t];
    memset(DP, 0x3f, sizeof(DP)); // Set INF
    for(int t = 1; t < N; t++) {
        DP[t][t] = 0;
        SUM[t] = SUM[t - 1] + A[t];
    }
    for(int len = 2; len <= N; len++) {
        for(int l = 1; l <= N - len + 1; l++) {
            int r = l + len - 1;
            for(int k = l; k < r; k++) {
                DP[l][r] = min(DP[l][r], DP[l][k] + DP[k + 1][r]);
            }
            DP[l][r] += SUM[r] - SUM[l - 1];
        }
    }
    cout << DP[1][N] << endl;
    return 0;
}