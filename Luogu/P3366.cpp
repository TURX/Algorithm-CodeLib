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
} S; // Define a classic union-find set.

inline bool cmp(Edge& l, Edge& r) {
    return l.w < r.w;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M; // Let N represents the number of nodes, M represents the number of edges.
    S.init(N); // Initialize N union-find set.
    for(int t = 0; t < M; t++) {
        cin >> E[t].u >> E[t].v >> E[t].w;
    } // Input all M edges.
    sort(E, E + M, cmp); // Sort by weight.
    for(int t = 0; t < M; t++) {
        int eu = S.find(E[t].u); // Find where the E[t] originally comes from.
        int ev = S.find(E[t].v); // Find where the E[t] finally goes to.
        if(eu == ev) continue; // E[t].u == E[t].v: Loop, cannot calculate.
        total += E[t].w; // Add current weight to the total weight.
        S.ufset[ev] = eu; cnt++; // Update S.ufset(S.find(E[t].v)) to S.find(E[t].u), add 1 to cnt.
        if(cnt == N - 1) break;
    }
    cout << total << endl;
    return 0;
}