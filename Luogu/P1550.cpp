// https://www.luogu.org/blog/yjx/p1550-usaco08oct-da-jing-watering-hole

#include <iostream>
#include <algorithm>
using namespace std;

int N, total, cnt = 1, W[401], P[401][401], x;
struct Edge{
    int u, v, w;
} E[161203];
struct ufset{
    int ufset[5001];
    inline void init(const int& n) {
        for(int t = 1; t <= n; t++)
            ufset[t] = t;
    }
    inline int find(int x) {
        // while(x != ufset[x]) x = ufset[x];
        // return x;
        return ufset[x] == x ? x : (ufset[x] = find(ufset[x]));
    }
} S;

inline bool cmp(Edge& l, Edge& r) {
    return l.w < r.w;
}

int main() {
    // N: Points
    ios::sync_with_stdio(false);
    cin >> N;
    S.init(N);
    for(int t = 1; t <= N; t++) {
        cin >> W[t];
        E[cnt++] = (Edge){0, t, W[t]};
        // cin >> E[t].u >> E[t].v >> E[t].w;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N;j++) {
            cin >> P[i][j];
            if(i > j) E[cnt++] = (Edge){i, j, P[i][j]};
        }
    }
    sort(E + 1, E + cnt + 1, cmp);
    for(int t = 1; t <= cnt; t++) {
        int eu = S.find(E[t].u);
        int ev = S.find(E[t].v);
        if(eu == ev) continue; // Loop
        total += E[t].w;
        S.ufset[ev] = eu; x++;
        if(x == N) break;
    }
    cout << total << endl;
    return 0;
}