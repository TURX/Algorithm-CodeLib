#pragma GCC optimize("O3")
#include <iostream>
#include <cstdio>
using namespace std;
int f[1000005][105], logA[1000005];
int N, M;
// const int INF = 0x7fffffff;

inline int query(const int& l, const int& r) {
    int p = logA[r - l + 1];
    return min(f[l][p], f[r - (1 << p) + 1][p]);
}

inline void init() {
    logA[1] = 0;
    for(int i = 2; i <= N; i++) {
        logA[i] = logA[i >> 1] + 1;
    }
}

inline void pre() {
    for(int p = 1; (1 << p) <= N; p++) {
        for(int i = 1; i + (1 << p) - 1 <= N; i++) {
            f[i][p] = min(f[i][p - 1], f[i + (1 << (p - 1))][p - 1]);
        }
    }
}

inline int at(const int& n) {
    return n < 1 ? 1 : n;
}

int main() {
    scanf("%d %d", &N, &M);
    init();
    //f[0][0] = INF;
    for(int i = 1; i <= N; i++) scanf("%d", &f[i][0]);
    pre();
    cout << 0 << endl;
    for(int i = 2; i <= N; i++) {
        printf("%d\n", query(at(i - M), at(i - 1)));
    }
    return 0;
}