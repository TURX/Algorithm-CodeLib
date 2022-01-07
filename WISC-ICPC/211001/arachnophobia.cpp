#include <iostream>
#include <queue>
using namespace std;

// 1. 首先 for each spider，设 dist(spider) = 0, 跑一遍 dijkstra，得到每个节点到任意 spider 的最短距离
// 2. 由于答案具有二分性质（如果一个答案合法，比它小的宽松答案肯定也合法），我们二分答案，check 时我们从源点出发跑 dijkstra，对于一个节点，在遍历 neighbor 并松弛前不但判断是否已经访问过，还判断是否越过了我们控制的到 spider 的最短距离，还有，在最后还得判断这条路是否超时

#define MAXN 100003
#define MAXM 1000003

struct Vertex {
    int to;
    unsigned long long weight;
    bool operator <(const Vertex& rhs) const {
        return weight > rhs.weight;
    }
};
vector<Vertex> g[MAXN];

bool visited[MAXN], reachedA = false;
int N, M, S, u, v;
int ans[MAXN], ansLength = 0;
unsigned long long w, dist[MAXN];

void dijkstra() {
    priority_queue<Vertex> Q;
    Q.push({S, 0});
    dist[S] = 0;
    while (!Q.empty()) {
        Vertex u = Q.top(); Q.pop();
        if (visited[u.to]) continue;
        visited[u.to] = true;
        for (int i = 0; i < g[u.to].size(); i++) {
			int v = g[u.to][i].to;
			int w = g[u.to][i].weight;
            if (dist[v] > dist[u.to] + w) {
	            dist[v] = dist[u.to] + w;
	            Q.push({v, dist[v]});
            }
        }
    }
}

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	int N, M, T;
}
