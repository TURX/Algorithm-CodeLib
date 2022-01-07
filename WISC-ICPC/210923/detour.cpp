#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

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
int pre[MAXN], ans[MAXN], ansLength = 0;
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
				pre[v] = u.to; // inversed, from D to A
	            dist[v] = dist[u.to] + w;
	            Q.push({v, dist[v]});
            }
        }
    }
}

void dfs(int current, int previous) {
	if (visited[current]) return;
	ans[ansLength] = current;
	ansLength++;
	visited[current] = true;
	if (current == 2) { // Amsterdam
		reachedA = true;
		cout << ansLength;
		for (int i = 0; i < ansLength; i++) {
			cout << " " << ans[i] - 1;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < g[current].size(); i++) {
		int v = g[current][i].to;
		if (pre[current] == v)
			continue;
		dfs(v, current);
		if (reachedA) return;
	}
	ansLength--;
}

int main() {
	// freopen("test.in", "r", stdin);
	// vertex index start from 1
	// 1: (original 0) Delft
	// 2: (original 1) Amsterdam
    cin >> N >> M;
	S = 2;
    for (int t = 0; t < M; t++) {
        cin >> u >> v >> w;
		u++; v++;
        g[u].push_back({v, w});
		g[v].push_back({u, w});
    }
	memset(pre, -1, sizeof(pre));
    memset(dist, ULLONG_MAX, sizeof(dist));
    dijkstra();
	memset(visited, false, sizeof(visited));
	dfs(1, -1);
	if (!reachedA) {
		cout << "impossible" << endl;
	}
    return 0;
}
