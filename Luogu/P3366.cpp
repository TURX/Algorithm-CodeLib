#include <iostream>
#include <algorithm>
using namespace std;

int N, M, total, cnt;
struct Edge{
    int u, v, w;
} E[200001];
struct ufset{
    int ufset[5001];
    inline void init(int& n) {
        for(int t = 1; t < n; t++)
            ufset[t] = t;
    }
    inline int find(int& x) {
        while(x != ufset[x]) x = ufset[x];
        return x;
    }
} S;

inline bool cmp(Edge& l, Edge& r) {
    return l.w < r.w;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    S.init(N);
    for(int t = 0; t < M; t++) {
        cin >> E[t].u >> E[t].v >> E[t].w;
    }
    sort(E, E + M, cmp);
    for(int t = 0; t < M; t++) {
        int eu = S.find(E[t].u);
        int ev = S.find(E[t].v);
        if(eu == ev) continue; // Loop
        total += E[t].w;
        S.ufset[ev] = eu; cnt++;
        if(cnt == N - 1) break;
    }
    cout << total << endl;
    return 0;
}