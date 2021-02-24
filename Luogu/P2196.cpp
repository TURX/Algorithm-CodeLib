#include <iostream>
using namespace std;

#define maxn 21

int n, cnt[maxn], conn[maxn][maxn], dp[maxn], pre[maxn], pos;

void print(int x) {
    if (pre[x] != 0) {
        print(pre[x]);
    }
    cout << x << " ";
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> conn[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = cnt[i];
        for (int j = 1; j < i; j++) {
            if (conn[j][i] == 1) {
                if (cnt[i] + dp[j] > dp[i]) {
                    dp[i] = cnt[i] + dp[j];
                    pre[i] = j;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] > dp[pos]) {
            pos = i;
        }
    }
    print(pos);
    cout << endl;
    cout << dp[pos] << endl;
    return 0;
}
