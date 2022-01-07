int R, C, GR, GC, LR, LC;
/*
void dfs(int x, int y, int numStep) {
	if (numStep >= ans) return;
	if (x < 1 || x > 100 || y < 1 || y > 100) return;
	if (visited[x][y]) return;
	visited[x][y] = true;
	if (x == LR && y == LC) {
		visited[x][y] = false;
		ans = numStep;
		found = true;
		return;
	}
	numStep++;
	dfs(x + 1, y + 2, numStep);
	dfs(x + 2, y + 1, numStep);
	dfs(x + 2, y - 1, numStep);
	dfs(x + 1, y - 2, numStep);
	dfs(x - 1, y - 2, numStep);
	dfs(x - 2, y - 1, numStep);
	dfs(x - 2, y + 1, numStep);
	dfs(x - 1, y + 2, numStep);
	visited[x][y] = false;
}
*/

		// found = false;
		// ans = INT32_MAX;
		if (ans == 0x7f7f7f7f) cout << "impossible" << endl;
// dfs(GR, GC, 0);