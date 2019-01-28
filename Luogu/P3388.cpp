#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define MAXN 20003

int N, M, tot, dfn[MAXN], low[MAXN], c[MAXN], cnt, X, Y, totalCut;
vector<int> G[MAXN], SCC[MAXN];
bool ins[MAXN], cut[MAXN];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tot;
    ins[u] = 1;
    int child = 0;
    for(int i = 0; i < G[u].size(); i++) {
        if(!dfn[G[u][i]]) {
            tarjan(G[u][i], fa);
            low[u] = min(low[u], low[G[u][i]]);
            if(low[G[u][i]] >= dfn[u] && u != fa) {
                cut[u] = true;
            }
            if(u == fa) {
                child++;
            }
        } else if (ins[G[u][i]] && low[u] > dfn[G[u][i]]) {
            low[u] = dfn[G[u][i]];
        }
    }
    if(dfn[u] == low[u]) {
        cnt++; int y;
        while(u != y) {
            y = u;
            ins[y] = 0;
            c[y] = cnt;
            SCC[cnt].push_back(y);
        }
    }
    if(child >= 2 && u == fa) {
        cut[u] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int t = 1; t <= M; t++) {
        cin >> X >> Y;
        G[X].push_back(Y);
        G[Y].push_back(X);
    }
    for(int t = 1; t <= N; t++) {
        if(!dfn[t]) tarjan(t, t);
    }
    for(int t = 1; t <= N; t++) {
        if(cut[t]) totalCut++;
    }
    cout << totalCut << endl;
    for(int t = 1; t <= N; t++) {
        if(cut[t]) cout << t << ' ';
    }
    cout << endl;
    return 0;
}