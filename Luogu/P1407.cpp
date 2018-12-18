#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define MAXN 20003

int N, M, tot, dfn[MAXN], low[MAXN], c[MAXN], cnt;
string girl, boy;
map<string, int> indexByName;
vector<int> G[MAXN], SCC[MAXN];
bool ins[MAXN];

struct Stack {
    int data[MAXN], pos = 0;
    inline int top() {
        return data[pos];
    }
    inline void push(const int& x) {
        data[++pos] = x;
    }
    inline void pop() {
        pos--;
    }
} S;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    S.push(u), ins[u] = 1;
    for(int i = 0; i < G[u].size(); i++) {
        if(!dfn[G[u][i]]) {
            tarjan(G[u][i]);
            low[u] = min(low[u], low[G[u][i]]);
        } else if (ins[G[u][i]] && low[u] > dfn[G[u][i]]) {
            low[u] = dfn[G[u][i]];
        }
    }
    if(dfn[u] == low[u]) {
        cnt++; int y;
        while(u != y) {
            y = S.top(); S.pop();
            ins[y] = 0;
            c[y] = cnt;
            SCC[cnt].push_back(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 1; t <= N; t++) {
        cin >> girl >> boy;
        indexByName[girl] = t;
        indexByName[boy] = t + N;
        G[indexByName[girl]].push_back(indexByName[boy]);
    }
    cin >> M;
    for(int t = 1; t <= M; t++) {
        cin >> girl >> boy;
        G[indexByName[boy]].push_back(indexByName[girl]);
    }
    for(int t = 1; t <= (N << 1); t++) {
        if(!dfn[t]) tarjan(t);
    }
    for(int t = 1; t <= N; t++) {
        if(c[t] == c[t + N]) cout << "Unsafe" << endl;
        else cout << "Safe" << endl;
    }
    return 0;
}