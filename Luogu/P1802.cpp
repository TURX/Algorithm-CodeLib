#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 1003

long long n, x, lose, win, use, dp[maxn];

int main() {
    cin >> n >> x;
    for (int j = 0; j < n; j++) {
        cin >> lose >> win >> use;
        for (int i = 0; i <= x - use; i++) {
            dp[i] = max(dp[i] + lose, dp[i + use] + win);
        }
        for (int i = x - use + 1; i <= x; i++) {
            dp[i] += lose;
        }
    }
    cout << dp[0] * 5 << endl;
    return 0;
}
