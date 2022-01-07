#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 2503

int N, E[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool dfs(int u, int v) {
	if (visited[u][v]) return false;
	visited[u][v] = true;
}

int main() {
	freopen("test.in", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> E[i][j];
	return 0;
}
