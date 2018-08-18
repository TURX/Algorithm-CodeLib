#include <cstdio>

typedef long long ll;
const int MAXN = 1e7 + 5, INF = 0x3f3f3f3f;

int n, m, s, cur, fr, re;
int a[MAXN], c[MAXN];
ll q[MAXN];

void generate_array(int a[], int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 0; i < n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a[i] = x % m + 1;
    }
}

ll getmin() {
    if (cur == n) return q[fr++];
    if (fr == re || a[cur] < q[fr]) return a[cur++];
    return q[fr++];
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    generate_array(a, n, m, s);
    for (int i = 0; i < n; ++i) c[a[i]]++;

    n = 0;
    for (int i = 1; i <= m; ++i) {
        for (; c[i]; c[i]--) a[n++] = i;
    }

    cur = 0;
    for (int i = 1; i <= n - 1; ++i) {
        ll x = getmin(), y = getmin();
        if (y < x + x) y = x + x;
        q[re++] = y;
    }
    printf("%lld\n", getmin());
}