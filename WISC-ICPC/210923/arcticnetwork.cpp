#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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

int N, S, P;
int F[600001];
vector<double> ans;

int ufs(int x) { // union-find set
	if (x == F[x]) return x;
	return F[x] = ufs(F[x]);
}

bool laf(int lhs, int rhs) {
	return lhs > rhs;
}

void kruskal(Vertex V[], Edge E[], int numEdges) {
	sort(E + 1, E + numEdges);
	for (int i = 1; i <= P; i++)
		F[i] = i;
	for (int i = 1; i < numEdges; i++) {
		int x = ufs(E[i].u);
		int y = ufs(E[i].v);
		if (x == y) continue;
		F[x] = y;
		ans.push_back(E[i].w);
	}
	sort(ans.begin(), ans.end());
}

double square(double x) {
	return x * x;
}

int main() {
	// freopen("test.in", "r", stdin);
	cin >> N;
	while (N--) { // for every case
		cin >> S >> P;
		Vertex V[P + 3];
		Edge E[P * P + 7];
		for (int i = 1; i <= P; i++) {
			cin >> V[i].x >> V[i].y; // rectangular coordinates
		}
		int numEdges = 1;
		for (int i = 1; i <= P; i++) {
			for (int j = i + 1; j <= P; j++) {
				// construct edges for undirected graph
				double dist = sqrt(square(V[i].x - V[j].x) + square(V[i].y - V[j].y));
				E[numEdges++] = Edge(i, j, dist);
				E[numEdges++] = Edge(j, i, dist);
			}
		}
		kruskal(V, E, numEdges);
		if (S == 0) S = 1;
		printf("%.2f\n", ans[P - S - 1]);
		memset(F, 0, sizeof(F));
		ans.clear();
	}
	return 0;
}
