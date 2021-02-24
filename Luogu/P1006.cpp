// https://www.luogu.org/blog/user26182/solution-p1006

#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 51

int M, N;
int matrix[MAXN][MAXN], dp[MAXN << 1][MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    dp[2][1][1] = 0;
    cin >> M >> N;
    for(int x = 1; x <= M; x++) {
        for(int y = 1; y <= N; y++) {
            cin >> matrix[x][y];
        }
    }
    for(int k = 3; k < M + N; k++) {
        for(int x = 1; x < N; x++) {
            for(int y = x + 1; y <= N; y++) {
                dp[k][x][y] = max(dp[k - 1][x - 1][y], max(dp[k - 1][x][y - 1], max(dp[k - 1][x - 1][y - 1], max(dp[k - 1][x][y], dp[k][x][y]))));
                if(dp[k][x][y] == -1) continue; // Cannot pass through
                dp[k][x][y] += matrix[k - x][x] + matrix[k - y][y]; // The maximum previous value
            }
        }
    }
    cout << dp[M + N - 1][N - 1][N] << endl;
    return 0;
}