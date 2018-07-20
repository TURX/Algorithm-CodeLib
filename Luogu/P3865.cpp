#include <iostream>
using namespace std;
int f[100005][20], low[100005];
int N, M;

inline int query(int& l, int& r) {
    int p = low[r - l + 1];
    return max(f[l][p], f[r - (l << p) + 1][p]);
}

inline void init() {
    low[1] = 0;
    for(int i = 2; i <= N; i++) {
        low[i] = low[i >> 1] + 1;
    }
}

inline void pre() {
    for(int p = 1; (1 << p) <= N; p++) {
        for(int i = 1; i + (1 << p) - 1 <= N; i++) {
            f[i][p] = max(f[i][p - 1], f[i + (1 << (p - 1))][p - 1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    init();
    for(int i = 1; i <= N; i++) cin >> f[i][0];
    pre();
    int l, r;
    while(M--) {
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}