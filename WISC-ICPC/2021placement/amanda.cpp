#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAXN 200001
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii; typedef vector<int> vi;

int N, M, a, b, c, cnt = 0;
vector<pii> G;

vi edgeColoring(int N, vector<pii> eds) {
	vi cc(N + 1), ret(sz(eds)), fan(N), free(N), loc;
	for (pii e : eds)
		++cc[e.first], ++cc[e.second];
	int u, v, ncols = *max_element(all(cc)) + 1;
	vector<vi> adj(N, vi(ncols, -1));
	for (pii e : eds) {
		tie(u, v) = e;
		fan[0] = v;
		loc.assign(ncols, 0);
		int at = u, end = u, d, c = free[u], ind = 0, i = 0;
		while (d = free[v], !loc[d] && (v = adj[u][d]) != -1)
			loc[d] = ++ind, cc[ind] = d, fan[ind] = v;
		cc[loc[d]] = c;
		for (int cd = d; at != -1; cd ^= c ^ d, at = adj[at][cd])
			swap(adj[at][cd], adj[end = at][cd ^ c ^ d]);
		while (adj[fan[i]][d] != -1) {
			int left = fan[i], right = fan[++i], e = cc[i];
			adj[u][e] = left;
			adj[left][e] = u;
			adj[right][e] = -1;
			free[right] = e;
		}
		adj[u][d] = fan[i];
		adj[fan[i]][d] = u;
		for (int y : {fan[0], u, end})
			for (int &z = free[y] = 0; adj[y][z] != -1; z++)
				;
	}
	rep(i, 0, sz(eds)) for (tie(u, v) = eds[i]; adj[u][ret[i]] != v;)++ ret[i];
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		G.push_back(pii(u, v));
		G.push_back(pii(v, u));
	}
	vi result = edgeColoring(N, G);
	cout << endl;
}
