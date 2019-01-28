// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
using namespace std;

struct E {
    int v, next;
} Edge[1000005];
int head[500005], tot = 1, depth[500005], fa[500005][20];

void addEdge(int u, int v) {
    Edge[tot].v = v;
    Edge[tot].next = head[u];
    head[u] = tot;
    tot++;
}

void preProcess(int x = 1, int father = 0) {
    depth[x] = depth[father] + 1;
    fa[x][0] = father;
    for(int i = 1; i <= 19 && fa[x][i - 1]; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for(int i = head[x]; i; i = Edge[i].next) {
        if(Edge[i].v != father) {
            preProcess(Edge[i].v, x);
        }
    }
}

inline int lca(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    int dis = depth[x] - depth[y];
    for(int i = 19; i + 1; i--)
        if(dis & (1 << i)) x = fa[x][i];
    if(x == y) return x;
    for(int i = 19; i + 1; i--) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x == y) return x;
    return fa[x][0];
}

int main() {
    int N, M, S, a, b;
    scanf("%d %d %d", &N, &M, &S);
    for(int i = 1; i < N; i++) {
        cin >> a >> b;
        addEdge(a, b);
        addEdge(b, a);
    }
    preProcess(S, 0);
    while(M--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}