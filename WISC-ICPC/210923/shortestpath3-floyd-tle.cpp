#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXN 1003
#define MAXM 5003
const int INF = 0x3f3f3f3f;

int dist[MAXN][MAXN], N, M, Q, S;

int main() {
	// freopen("test.in", "r", stdin);
	while (true) {
		// Input
		cin >> N >> M >> Q >> S;
		if (N == 0 && M == 0 && Q == 0 && S == 0) break;
		S++;
		memset(dist, INF, sizeof(dist));
		for (int i = 1; i <= N; i++)
			dist[i][i] = 0;
		for (int i = 1; i <= M; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u++; v++;
			dist[u][v] = min(dist[u][v], w);
		}
		// Floyd
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		// Query
		while (Q--) {
			int v;
			cin >> v;
			v++;
			if (dist[v][v] < 0) {
				cout << "-Infinity" << endl;
			} else {
				int ans = dist[S][v];
				if (ans == INF) cout << "Impossible" << endl;
				else cout << ans << endl;
			}
		}
	}
	return 0;
}
