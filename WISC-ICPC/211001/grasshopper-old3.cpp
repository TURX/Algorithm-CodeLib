#include <iostream>
#include <queue>
using namespace std;

struct Vertex {
	int x, y;
	Vertex(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Vertex() {}
};

int R, C, GR, GC, LR, LC;
int dist[101][101];
queue<Vertex> Q;

Vertex offsets[8] = {Vertex(1, 2), Vertex(2, 1), Vertex(2, -1), Vertex(1, -2), Vertex(-1, -2), Vertex(-2, -1), Vertex(-2, 1), Vertex(-1, 2)};

bool valid(int x, int y) {
	return x >= 1 && x <= R && y >= 1 && y <= C;
}

int bfs() {
	Q.push(Vertex(GR, GC));
	dist[GR][GC] = 0;
	while (!Q.empty()) {
		Vertex u = Q.front(); Q.pop();
		for (int i = 0; i < 8; i++) {
			Vertex v = Vertex(u.x + offsets[i].x, u.y + offsets[i].y);
			if (v.x == LR && v.y == LC) {
				dist[v.x][v.y] = dist[u.x][u.y] + 1;
				return dist[LR][LC];
			}
			if (!valid(v.x, v.y)) {
				continue;
			}
			if (dist[v.x][v.y] == -1) {
				Q.push(v);
				dist[v.x][v.y] = dist[u.x][u.y] + 1;
			}
		}
	}
	return -1;
}

int main() {
	freopen("test.in", "r", stdin);
	while (cin >> R >> C >> GR >> GC >> LR >> LC) {
		if (GR == LR && GC == LC) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i < 101; i++)
			for (int j = 1; j < 101; j++)
				dist[i][j] = -1;
		while (!Q.empty()) Q.pop();
		int ans = bfs();
		if (ans == -1) cout << "impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}
