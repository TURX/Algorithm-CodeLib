// https://sshoj.blog.luogu.org/solution-cf607b
#define INF 0x7ffffffff
#include <iostream>
using namespace std;

int n, s[501], dp[501][501];

int solve(const int& l, const int& r) {
    if()
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int t = 0; t < n; t++) cin >> s[t];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    cout << solve(1, n) << endl;
    return 0;
}