#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 10003


int N, M, S;
unsigned long long x, y, w;
struct Edge {
	int to;
    unsigned long long weight;
	inline friend bool operator <(const Edge& lhs, const Edge& rhs) {
		return lhs.weight < rhs.weight;
	}
};
vector<Edge> G[MAXN];
unsigned long long dis[MAXN];
bool vis[MAXN];
// N: Total number of points

void Dijkstra() {
	priority_queue<Edge> pq;
	pq.push({S, 0});
	dis[S] = 0;
	while(!pq.empty()) {
		Edge current = pq.top();
		pq.pop();
        int u = current.to;
        unsigned long long d = current.weight;
		if(vis[current.to]) continue;
		vis[current.to] = true;
		for(int t = 0; t < G[current.to].size(); t++) {
			if(dis[G[current.to][t].to] > dis[current.to] + G[current.to][t].weight) {
				dis[G[current.to][t].to] = dis[current.to] + G[current.to][t].weight;
				pq.push({G[current.to][t].to, dis[G[current.to][t].to]});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> S;
	for(int t = 1; t <= M; t++) {
		cin >> x >> y >> w;
		G[x].push_back({y, w});
	}
	memset(dis, 500003, sizeof(dis));
	Dijkstra();
	for(int t = 1; t <= N; t++) {
		cout << dis[t] << " ";
	}
	cout << endl;
	return 0;
}