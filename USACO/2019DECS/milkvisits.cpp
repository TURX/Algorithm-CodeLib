#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100001;

int N, M, x, y, z;

struct Tree {
	int father;
	vector<int> children;
	bool type;
} tree[MAXN];

bool flag = false;

bool dfs(int u, const int& v, const bool& pref) {
	if (tree[u].type == pref) {
		flag = true;
		return true;
	}
	if (u == v) return false;
	for (int i = 0; i < tree[u].children.size(); i++)
		if (dfs(tree[u].children[i], v, pref) == true)
			return true;
	return false;
}

int main() {
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	cin >> N >> M;
	x = getchar();
	for (int i = 1; i <= N; i++) {
		x = getchar();
		tree[i].type = (x == 'G');
	}
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		tree[x].children.push_back(y);
		tree[y].father = x;
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		flag == false;
		dfs(x, y, z == 'G');
		cout << (int)flag;
	}
	cout << endl;
}