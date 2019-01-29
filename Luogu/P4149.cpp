#include <iostream>
#include <vector>
using namespace std;

#define MAXN 200001
// 给一棵树，每条边有权。求一条简单路径，权值和等于K，且边的数量最小。

struct Edge {
    int v, w;
};
int N, K, u, v, w, capacity;
vector<Edge> G[MAXN];

void findCenterOfGravity(int u, int fa) {
    siz[u] = 1, son[u] = 0;
    for (int i = head[u]; i != -1; i = edges[i].nxt)
    {
        int to = edges[i].to, w = edges[i].weight;
        if (to == fa || vis[to])
            continue;
        findCenterOfGravity(to, u);
        siz[u] += siz[to], son[u] = max(siz[to], son[u]);
    }
    son[u] = max(son[u], capacity - siz[u]);
    if (son[u] < son[root])
        root = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int t = 0; t < N - 1; t++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    capacity = N; // capacity即为树的总容量，即为树上节点的数量
    return 0;
}