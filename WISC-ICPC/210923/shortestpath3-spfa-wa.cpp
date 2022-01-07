#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXN 1003
#define MAXM 5003
const int INF = 0x7f7f7f7f;

struct Edge {
	int v, w;
	Edge(int v, double w) {
		this->v = v;
		this->w = w;
	}
	Edge() {}
};

bool visited[MAXN], neg[MAXN];
int dist[MAXN], cnt[MAXN], N, M, Q, S;
vector<Edge> G[MAXN];
queue<int> U;

void spfa() {
	dist[S] = 0;
	visited[S] = true;
	U.push(S);
	while (!U.empty()) {
		int u = U.front(); U.pop();
		visited[u] = false;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v;
			int w = G[u][i].w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] > N) {
					neg[u] = true;
					continue;
				}
				if (!visited[v]) {
					U.push(v);
					visited[v] = true;
				}
			}
		}
	}
}

int main() {
	// freopen("test.in", "r", stdin);
	while (true) {
		cin >> N >> M >> Q >> S;
		if (N == 0 && M == 0 && Q == 0 && S == 0) break;
		S++;
		memset(dist, INF, sizeof(dist));
		memset(cnt, 0, sizeof(cnt));
		memset(visited, false, sizeof(visited));
		memset(neg, false, sizeof(neg));
		for (int i = 1; i <= N; i++) {
			G[i].clear();
		}
		while (!U.empty()) U.pop();
		for (int i = 1; i <= M; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u++; v++;
			G[u].push_back(Edge(v, w));
		}
		spfa();
		while (Q--) {
			int v;
			cin >> v;
			v++;
			if (neg[v]) {
				cout << "-Infinity" << endl;
			} else {
				int ans = dist[v];
				if (ans == INF) cout << "Impossible" << endl;
				else cout << ans << endl;
			}
		}
	}
	return 0;
}
