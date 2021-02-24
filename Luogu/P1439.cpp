#include <iostream>
using namespace std;

#define MAXN 10000

int N, A[MAXN], B[MAXN], dp[MAXN][MAXN], i, j;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (i = 1; i <= N; i++) cin >> A[i];
    for (i = 1; i <= N; i++) cin >> B[i];
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i] == B[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[N][N] << endl;
}