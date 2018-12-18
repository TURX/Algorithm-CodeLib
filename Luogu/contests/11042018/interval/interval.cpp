#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long LL;

LL N, a[4000003], lastGcd = 0, currentGcd, maxLen;

inline LL GCD(LL a, LL b) {
    if(a == 0) return b;
	if(b) while((a %= b) && (b %= a));
	return a + b;
}

inline LL read()
{
    LL x = 0, f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = (x << 3) + (x << 1) + c - '0';
    return x * f;
}

int main() {
    freopen("interval.in", "r", stdin);
    freopen("interval.out", "w", stdout);
    ios::sync_with_stdio(false);
    N = read();
    for(LL t = 0; t < N; t++) a[t] = read();
    for(LL l = 0; l < N; l++) {
        for(LL r = l; r < N; r++) {
            if(r - l <= maxLen) continue;
            currentGcd = GCD(lastGcd, a[r]);
            if(currentGcd != 1) lastGcd = currentGcd;
            for(LL k = l; k <= r; k++) {
                if(a[k] == lastGcd) maxLen = max(maxLen, r - l);
            }
        }
    }
    cout << maxLen << endl;
    return 0;
}