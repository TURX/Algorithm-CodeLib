#include <iostream>
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

int main() {
	int N, S, P;
	cin >> N;
	while (N--) { // for every case
		
	}
	return 0;
}
