#include <iostream>
#include <climits>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 2001
#define MAXD 21

int n, d;
unsigned long long ans;
unsigned long long dp[MAXN][MAXD], price[MAXN];

unsigned long long round(unsigned long long x) {
    return ((x + 5) / 10) * 10;
}

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
        price[i] += price[i - 1]; // 前缀和
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= d + 1; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = round(price[i]);
	}
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d + 1; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + round(price[i] - price[k]));
            }
        }
    }
    ans = INF;
    for (int j = 1; j <= d + 1; j++) {
        ans = min(ans, dp[n][j]);
    }
    cout << ans << endl;
    return 0;
}
