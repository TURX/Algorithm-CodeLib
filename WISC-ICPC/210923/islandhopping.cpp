#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

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

int N, M;
int F[600001];

int ufs(int x) { // union-find set
	if (x == F[x]) return x;
	return F[x] = ufs(F[x]);
}

double kruskal(Vertex V[], Edge E[], int numEdges) {
	double ans = 0;
	sort(E + 1, E + numEdges); // + 1?
	for (int i = 1; i <= M; i++)
		F[i] = i;
	for (int i = 1; i < numEdges; i++) {
		int x = ufs(E[i].u);
		int y = ufs(E[i].v);
		if (x == y) continue;
		F[x] = y;
		ans += E[i].w;
	}
	return ans;
}

double square(double x) {
	return x * x;
}

int main() {
	// freopen("test.in", "r", stdin);
	cin >> N;
	while (N--) { // for every case
		cin >> M;
		Vertex V[M + 3];
		Edge E[M * M + 7];
		for (int i = 1; i <= M; i++) {
			cin >> V[i].x >> V[i].y; // rectangular coordinates
		}
		int numEdges = 1;
		for (int i = 1; i <= M; i++) {
			for (int j = i + 1; j <= M; j++) {
				// construct edges for undirected graph
				double dist = sqrt(square(V[i].x - V[j].x) + square(V[i].y - V[j].y));
				E[numEdges++] = Edge(i, j, dist);
				E[numEdges++] = Edge(j, i, dist);
			}
		}
		cout << kruskal(V, E, numEdges) << endl;
		memset(F, 0, sizeof(F));
	}
	return 0;
}
