#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Block {
	bool visited;
	int num;
	vector<int> factors;
} map[1001][1001];

int n, m, i, j, k;

bool dfs(const int& x, const int& y) {
	if (x == m && y == n) return true;
	if (x <= 0 || x > m || y <= 0 || y > n)
		return false;
	if (map[x][y].visited)
		return false;
	map[x][y].visited = true;
	for (int t = 0; t < map[x][y].factors.size(); t++) {
		int nx = map[x][y].factors[t], ny = map[x][y].num / map[x][y].factors[t];
		if (dfs(nx, ny) == true)
			return true;
	}
	map[x][y].visited = false;
	return false;
}

int main() {
	cin >> m >> n;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			cin >> map[i][j].num;
			for (int k = 1; k <= sqrt(map[i][j].num); k++) {
				if (map[i][j].num % k == 0) {
					if (map[i][j].num / k == k)
						map[i][j].factors.push_back(k);
					else {
						map[i][j].factors.push_back(k);
						map[i][j].factors.push_back(map[i][j].num / k);
					}
				}
			}
		}
	}
	cout << (dfs(1, 1) ? "yes" : "no") << endl;
	return 0;
}
