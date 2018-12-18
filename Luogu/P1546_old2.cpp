// https://www.luogu.org/blog/chengni5673/solution-p1546

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 200002
#define MAXM 200002

int N, nodeCnt, ans, p = 1;

struct UFSetBox {
    int ufset[MAXN];
    int find(const int& x) {
        if(x == ufset[x]) return x;
        ufset[x] = find(ufset[x]);
        return ufset[x];
    }
} u;

struct Node {
    int u, v, w;
    inline bool operator <(const Node& rhs) const {
        return w < rhs.w;
    }
} n[MAXM];

int main() {
    freopen("testdata2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        u.ufset[i] = i;
        for(int j = 1; j <= N; j++) {
            int k;
            cin >> k;
            if(i >= j) continue;
            n[nodeCnt++].u = i;
            n[nodeCnt].v = j;
            n[nodeCnt].w = k;
        }
    }
    sort(n + 1, n + nodeCnt + 1);
    for(int i = 1; i <= nodeCnt; i++) {
        if(u.find(n[i].u) != u.find(n[i].v)) {
            ans += n[i].w;
            u.ufset[u.find(n[i].u)] = u.find(n[i].v);
            p++;
            if(p == N) break;
        }
    }
    cout << ans << endl;
    return 0;
}