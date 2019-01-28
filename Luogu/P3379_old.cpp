// https://www.luogu.org/blog/34188/solution-p3379

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int dest, next;
} nodes[1000001];
int N, M, S, nodeCnt, head[500001], depth[500001], fa[500001][23], lg[500001];

inline void add(int x, int y) {
    nodes[++nodeCnt] = {y, head[x]};
    head[x] = nodeCnt;
}

inline int lca(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    while(depth[x] > depth[y])
        x = fa[x][lg[depth[x] - depth[y] - 1]];
    if(x == y) return x;
    for(int t = lg[depth[x]]; t >= 0; t--) {
        if(fa[x][t] != fa[y][t]) {
            x = fa[x][t];
            y = fa[y][t];
        }
    }
    return fa[x][0];
}

inline void dfs(int current, int father) {
    depth[current] = depth[father] + 1;
    fa[current][0] = father;
    for(int t = 1; (1 << t) <= depth[current]; t++)
        fa[current][t] = fa[fa[current][t - 1]][t - 1];
    for(int t = head[current]; t; t = nodes[t].next)
        if(nodes[t].dest != father) dfs(nodes[t].dest, current);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> M >> S;
    for(int t = 0; t < N - 1; t++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(S, 0); // Pre-procession
    for(int t = 1; t <= N; t++) {
        lg[t] = lg[t - 1] + (1 << lg[t - 1] == t);
    }
    for(int t = 1; t <= M; t++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
