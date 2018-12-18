#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 303
#define MAXM 100003
#define MAXW 10003

struct UFSet {
    int ufset[MAXN];
    inline int find(int& x) {
        while(x != ufset[x]) x = ufset[x];
        return x;
    }
    inline void init(const int& n) {
        for(int t = 1; t < n; t++) {
            ufset[t] = t;
        }
    }
} S;

struct Edge {
    int u, v, w;
    inline bool operator <(const Edge& rhs) const {
        return w < rhs.w;
    }
} E[MAXM];

int N, M, cnt, numberSelected, maxSelected;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    S.init(N);
    for(int t = 0; t < M; t++) {
        cin >> E[t].u >> E[t].v >> E[t].w;
    }
    sort(E, E + M);
    for(int t = 0; t < M; t++) {
        int eu = S.find(E[t].u); // Find where the E[t] originally comes from.
        int ev = S.find(E[t].v); // Find where the E[t] finally goes to.
        if(eu == ev) continue; // E[t].u == E[t].v: Loop, cannot calculate.
        maxSelected = max(E[t].w, maxSelected);
        numberSelected++;
        // total += E[t].w; // Add current weight to the total weight.
        S.ufset[ev] = eu; cnt++; // Update S.ufset(S.find(E[t].v)) to S.find(E[t].u), add 1 to cnt.
        if(cnt == N - 1) break;
    }
    cout << numberSelected << " " << maxSelected << endl;
    return 0;
}