#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long INF = 1e12;
int n, m;
struct edge
{
    int u, v, w;
} E[maxn];
vector<int> G[maxn];
int p[maxn]; // p[k]记录最短路上到达k的节点
long long dis[maxn];
bool vis[maxn];
struct Node
{
    int u, d; // u为此点的编号，d为此点经过的路程
    bool operator<(const Node &tmp) const
    {
        return d > tmp.d; // 根据路程降序排列得到最短路径
    }
};
priority_queue<Node> pq; // 优先队列排序找出最短路径
// Heap Dijkstra

bool Dijkstra()
{
    fill(dis + 1, dis + n + 1, INF); // 所有距离设置为无限
    fill(vis + 1, vis + n + 1, false); // 都没看见对方
    dis[1] = 0; // 设置第一个点到第一个点距离为0
    pq.push((Node){1, 0});
    while (!pq.empty())
    {
        Node tmp = pq.top();
        pq.pop();
        if (vis[tmp.u])
            continue;
        vis[tmp.u] = true;
        for (int i = 0; i < G[tmp.u].size(); ++i)
        {
            edge &e = E[G[tmp.u][i]];
            if (dis[e.v] > dis[e.u] + e.w)
            {
                dis[e.v] = dis[e.u] + e.w;
                pq.push((Node){e.v, dis[e.v]});
                p[e.v] = e.u; //“顺带”记录一下路径
            }
        }
    }
    return !(dis[n] == INF); //dis[n]==INF 即为不连通
}

void print_G(int k)
{ //递归打印路径
    if (p[k] != -1)
        print_G(p[k]); //递归终点，对应Give_Ans中p[1]=-1
    printf("%d ", k);
}

void Give_Ans(bool if_pas)
{ //判断答案是否存在
    if (!if_pas)
    {
        puts("-1");
        return;
    }
    p[1] = -1;
    print_G(n);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = (edge){u, v, w};
        E[i + m] = (edge){v, u, w}; //处理双向边
        G[u].push_back(i);
        G[v].push_back(i + m); //处理双向边
    }
    bool if_pas = Dijkstra();
    Give_Ans(if_pas);
    return 0;
}