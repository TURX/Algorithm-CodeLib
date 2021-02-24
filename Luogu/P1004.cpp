// TODO

#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;

#define maxn 10

int n, a, b, x, map[maxn][maxn], dp[maxn][maxn], tmp[maxn][maxn];

int main() {
    cin >> n;
    while (true) {
        cin >> a;
        if (a == 0) break;
        cin >> b >> x;
        map[a][b] = x;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tmp[i][j] = -INT32_MIN;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i + 1][j] = max(dp[i][j] + map[i + 1][j], tmp[i][j] + map[i + 1][j]);
            dp[i][j + 1];
        }
    }
    return 0;
}
