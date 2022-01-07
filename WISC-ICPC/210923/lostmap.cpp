#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 2501

struct Vertex {
	double x, y;
};

struct Edge {
	int u, v; // from, to
	double w; // weight
	friend bool operator <(Edge lhs, Edge rhs) {
		return lhs.w < rhs.w;
	}
	Edge(int u, int v, double w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
	Edge() {}
};

int N, numEdges = 1;
int F[600001];
Vertex V[MAXN];
Edge E[MAXN * MAXN];

int ufs(int x) { // union-find set
	if (x == F[x]) return x;
	return F[x] = ufs(F[x]);
}

void kruskal() {
	sort(E + 1, E + numEdges);
	for (int i = 1; i <= N; i++)
		F[i] = i;
	for (int i = 1; i < numEdges; i++) {
		int x = ufs(E[i].u);
		int y = ufs(E[i].v);
		if (x == y) continue;
		F[x] = y;
		cout << E[i].u << " " << E[i].v << endl;
	}
}

// 最小生成树，考虑边i->j：如果两者不连通，且当前边的权值最小则一定是修建的路。因为无法通过现有的边推导出更短的i->j。

int main() {
	// freopen("test.in", "r", stdin);
	cin >> N;
	int d;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> d;
			E[numEdges++] = Edge(i, j, d);
		}
	}
	kruskal();
	return 0;
}
