#include <iostream>
using namespace std;

int n, m, eptr;

struct Edge {
    int u, v;
} e[200001];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int t = 0; t < n; t++) {
        int u, v;
        cin >> u >> v;
        e[eptr++] = {u, v};
        e[eptr++] = {v, u};
    }
    for(int t = 0; t < m; t++) {
        int x, y;
        cin >> x >> y;
    }
    return 0;
}