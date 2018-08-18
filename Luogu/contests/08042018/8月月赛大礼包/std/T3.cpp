#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
int ch = 0;
template <class T> inline void read(T &a) {
    bool f = 0; a = 0;
    while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
    if (f) a = -a;
}

#define MOD 1000000007


LL power(LL x, LL y) {
    LL ret = 1;
    for (x %= MOD; y; y >>= 1) {
        if (y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

#define inv(x) power(x, MOD - 2)

int main() {
    int n, K;
    read(n); read(K);
    LL ans = inv(n);
    for (int i = 0; i < n - 2; i++) {
        if (i < K - 1 || (K && i == n - 3)) ans = (1 - ans) * inv(n - i - 2) % MOD;
    }
    cout << (ans + MOD) % MOD << endl;
    /*
    int t = 0;
    for (int i = 0; i < (1 << n); i++) {
        long double now = 1. / n;
        int k = 0;
        for (int j = 0; j < n - 2; j++) {
            if ((i >> j) & 1) {
                k++;
                assert(now < 1e-9 + ((1 - now) / (n - j - 2)));
                now = (1 - now) / (n - j - 2);
            }
        //	printf("%.9Lf\n", now);
        }
        if (k == K && now > ans) ans = now, t = i;
    }
    printf("%.9lf\n", (double)ans);
    for (int j = 0; j < n - 2; j++) printf("%d", (t >> j) & 1);
    printf("\n");*/
    return 0;
}


