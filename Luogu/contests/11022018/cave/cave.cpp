#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long LL;
#define MAXN 103
#define MAXM 10003
#define MAXL 100000003

struct Recurs {
    LL l, a, b;
} current;

LL N, M, Q, ui, vi, li, ai, bi;
vector<LL> G[MAXN];
Recurs *stackRes = new Recurs[MAXL];

struct Stack {
    LL ptr;
    inline void push(const Recurs& val) {
        stackRes[ptr++] = val;
    }
    inline void pop() {
        ptr--;
    }
    inline Recurs top() {
        return stackRes[ptr - 1];
    }
    inline bool empty() {
        return ptr == 0;
    }
} S;

inline bool dfs(const LL& l, const LL& a, const LL& b) {
    S.push({l, a, b});
    while(!S.empty()) {
        current = S.top(); S.pop();
        if(current.l == 0) {
            if(current.a == current.b) return true;
            continue;
        }
        for(int t = 0; t < G[current.a].size(); t++) {
            S.push({current.l - 1, G[current.a][t], b});
        }
    }
    return false;
}

/*
bool dfs_recursive(const LL& l, const LL& a, const LL& b) {
    if(l == 0) return a == b;
    for(int t = 0; t < G[a].size(); t++) {
        if(dfs(l - 1, G[a][t], b) == true) {
            return true;
        }
    }
    return false;
}
*/

int main() {
    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(LL t = 0; t < M; t++) {
        cin >> ui >> vi;
        G[ui].push_back(vi);
    }
    cin >> Q;
    for(LL t = 0; t < Q; t++) {
        cin >> li >> ai >> bi;
        if(dfs(li, ai, bi)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}