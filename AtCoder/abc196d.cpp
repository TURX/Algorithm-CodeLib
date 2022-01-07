// TODO

#include <iostream>
#include <set>
using namespace std;

int H, W, A, B;
bool M[17][17];
set<unsigned int> HT;

/*
void dfs(int x, int y, int a, int b, unsigned int hash) {
	if (x == W && y == H) {
		if (a == 0 && b == 0) HT.insert(hash);
		return;
	}
	if (x > W || y > H) return;
	if (a) {
		dfs(x + 2, y, a - 1, b, hash + 23213 * (x + 2) * y);
		dfs(x, y + 2, a - 1, b, hash + 31877 * x * (y + 2));
	}
	if (b) {
		dfs(x + 1, y, a, b - 1, hash + 12371 * (x + 1) * y);
		dfs(x, y + 1, a, b - 1, hash + 7099 * x * (y + 1));
	}
}
*/

int dfs(int x, int y, int a, int b) {
	if (y == H) return a == 0;
	if (x == W) return dfs(0, y, a, b);
	if (x > W || y > H) return 0;
	if (M[x][y]) return dfs(x + 1, y, a, b);
	int ans = 0;
	if (a) {
		ans += dfs(x + 2, y, a - 1, b);
		ans += dfs(x, y + 2, a - 1, b);
	}
	if (b) {
		ans += dfs(x + 1, y, a, b - 1);
		ans += dfs(x, y + 1, a, b - 1);
	}
	return ans;
}

int main() {
	cin >> H >> W >> A >> B;
	// dfs(0, 0, A, B, 0);
	// cout << HT.size() << endl;
	cout << dfs(0, 0, A, B) << endl;
}
