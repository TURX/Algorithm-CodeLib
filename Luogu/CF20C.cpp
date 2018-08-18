// Dijkstra
#define INF 1e12
#include <iostream>
#include <map>
#include <queue>
using namespace std;

unsigned index_ptr = 0;
long long n, m, u, v, w, head[100100], dis[100100];
struct Point
{
    long long distance;
    long long target;
    long long next;
} edge[500100 * 2];
struct Node
{
    long long u, d;
    bool operator<(Node &target)
    {
        return d > target.d;
    }
};
priority_queue<Node> pq;
map<long long, long long> index;
bool vis[100100];

inline void addEdge(long long &u, long long &v, long long &w)
{
    edge[u].target = v;
    edge[u].distance = w;
    edge[u].next = head[u];
    head[u] = u;
    index[index_ptr++] = u;
}

inline bool dijkstra()
{
    fill(dis, dis + n, INF);
    fill(vis, vis + n, false);
    dis[0] = 0;
    pq.push((Node){1, 0});
    while (!pq.empty())
    {
        Node tmp = pq.top();
        pq.pop();
        if (vis[tmp.u])
            continue;
        vis[tmp.u] = true;
        for (int i = 0; i < G[tmp.u].size(); ++i)
    }
}

int main()
{
    cin >> n >> m;
    for (long long t = 0; t < m; t++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    /*
    for(long long t = 0; t < n; t++) {
        dis[t] = 9223372036854775806;
        dis[s] = 0;
        ans[flag] = s;
    }
    */
    return 0;
}