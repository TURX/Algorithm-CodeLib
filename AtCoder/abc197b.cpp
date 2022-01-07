#include <iostream>
using namespace std;

#define MAXN 103

bool m[MAXN][MAXN], vis[MAXN][MAXN];
int H, W, X, Y, ans;
char c;
bool flgX, flgY;

void dfs(int x, int y) {
	if (vis[x][y] || m[x][y]) return;
	if (x != X && y != Y) return;
	if (x < 1 || x > H || y < 1 || y > W) return;
	ans++;
	vis[x][y] = true;
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
	vis[x][y] = false;
}

int main() {
	cin >> H >> W >> X >> Y;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> c;
			if (c == '#') {
				m[i][j] = true;
			}
		}
	}
	dfs(X, Y);
	cout << ans << endl;
}