#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Vertex {
	int x, y, step;
	Vertex(int x, int y, int step) {
		this->x = x;
		this->y = y;
		this->step = step;
	}
	Vertex(int x, int y) {
		this->x = x;
		this->y = y;
		this->step = 0;
	}
	Vertex() {}
};

int R, C, GR, GC, LR, LC;
bool visited[101][101];
queue<Vertex> Q;

Vertex offsets[8] = {Vertex(1, 2), Vertex(2, 1), Vertex(2, -1), Vertex(1, -2), Vertex(-1, -2), Vertex(-2, -1), Vertex(-2, 1), Vertex(-1, 2)};

bool valid(int x, int y) {
	return x >= 1 && x <= R && y >= 1 && y <= C;
}

int bfs() {
	Q.push(Vertex(GR, GC, 0));
	visited[GR][GC] = 1;
	while (!Q.empty()) {
		Vertex u = Q.front(); Q.pop();
		for (int i = 0; i < 8; i++) {
			Vertex v = Vertex(u.x + offsets[i].x, u.y + offsets[i].y, u.step + 1);
			if (v.x == LR && v.y == LC) {
				return v.step;
			}
			if (!valid(v.x, v.y)) {
				continue;
			}
			if (!visited[v.x][v.y]) {
				Q.push(v);
				visited[v.x][v.y] = true;
			}
		}
	}
	return -1;
}

int main() {
	// freopen("test.in", "r", stdin);
	while (cin >> R >> C >> GR >> GC >> LR >> LC) {
		if (GR == LR && GC == LC) {
			cout << 0 << endl;
			continue;
		}
		memset(visited, false, sizeof(visited));
		while (!Q.empty()) Q.pop();
		int ans = bfs();
		if (ans == -1) cout << "impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}
