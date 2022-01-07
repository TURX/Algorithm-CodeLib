#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXN 1003
#define MAXM 5003
const int INF = 0x3f3f3f3f;

struct Edge {
	int v, w;
	Edge(int v, int w)
	{
		this->v = v;
		this->w = w;
	}
	Edge() {}
};

vector<Edge> G[MAXN];
int dist[MAXN];
bool neg[MAXN];

int N, M, Q, S, x;

void bellmanFord() {
	dist[S] = 0;
	for (int i = 1; i <= N - 1; i++) {
		for (int u = 1; u <= N; u++) {
			for (Edge e : G[u]) {
				int v = e.v, w = e.w;
				if (dist[u] == INF) continue;
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int u = 1; u <= N; u++) {
			for (Edge e : G[u]) {
				int v = e.v, w = e.w;
				if (dist[u] == INF) continue;
				if (dist[v] > dist[u] + w) {
					// neg[u] = true;
					dist[v] = -INF;
				}
			}
		}
	}
}

int main() {
	freopen("test.in", "r", stdin);
	while (true) {
		cin >> N >> M >> Q >> S;
		if (N == 0 && M == 0 && Q == 0 && S == 0) break;
		S++;
		memset(dist, INF, sizeof(dist));
		// memset(neg, false, sizeof(neg));
		for (int i = 1; i <= N; i++) {
			G[i].clear();
		}
		for (int i = 1; i <= M; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u++; v++;
			G[u].push_back(Edge(v, w));
		}
		bellmanFord();
		while (Q--) {
			int v;
			cin >> v;
			v++;/*
			if (neg[v]) {
				cout << "-Infinity" << endl;
			} else {
				*/
				int ans = dist[v];
				if (ans == -INF) cout << "-Infinity" << endl;
				else if (ans == INF) cout << "Impossible" << endl;
				else cout << ans << endl;
			//}
		}
	}
	return 0;
}
