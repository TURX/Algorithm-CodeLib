// https://www.luogu.org/blog/user14908/ti-xie-p1005-ju-zhen-qu-shuo-you-hu-post

#include <iostream>
#include <cstring>
using namespace std;

int N, M, V[81];
unsigned long long dp[81][81], TMPow, ans, MA;


unsigned long long fastPow(int b, int p) {
    int ans = 1;
    while(p > 0) {
        if(p % 2 != 0) {
            ans *= b;
        }
        b *= b;
        p >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    while(N--) {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= M; i++) {
            cin >> V[i];
        }
        for(int i = 1; i <= M; i++) {
            for(int j = M; j >= i; j--) {
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j] + V[i - 1] * fastPow(2, M - (j - i) + 1), dp[i][j + 1] + V[j + 1] * fastPow(2, M - (j - i) + 1)));
                //dp[i][j] = max(dp[i + 1][j] * fastPow(M - (j - i), 2) * V[i], dp[i][j - 1] * fastPow(M - (j - i), 2) * V[j]);
            }
        }
    }
    TMPow = fastPow(2, M); MA = 0;
    for(int i = 1; i <= M; i++) {
        MA = max(MA, dp[i][i] + V[i] * TMPow);
        ans += MA;
    }
    cout << ans << endl;
    return 0;
}