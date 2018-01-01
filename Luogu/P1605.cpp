#include <iostream>
#include <memory.h>
using namespace std;
int graph[6][6], record[6][6], n, m, t, sx, sy, fx, fy, total = 0, next[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
void dfs(int x, int y) {
	int tx, ty, k;
	if (x == fx&&y == fy) {
		total++;
		return;
	}
	for (k = 0; k < 4; k++) {
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx > 0 && tx <= n && ty > 0 && ty <= m && graph[tx][ty] == 0 && record[tx][ty] == 0) {
			record[tx][ty] = 1;
			dfs(tx, ty);
			record[tx][ty] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> t >> sx >> sy >> fx >> fy;
	for (int i = 0, tx, ty; i < t; i++) {
		cin >> tx >> ty;
		graph[tx][ty] = 1;
	}
	record[sx][sy] = 1;
	dfs(sx, sy);
	cout << total << endl;
	return 0;
}
