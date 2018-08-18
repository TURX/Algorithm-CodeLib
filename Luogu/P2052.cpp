// NOI2011 道路修建
// https://www.luogu.org/blog/wlz123/solution-p2052

#include <iostream>
using namespace std;

struct Edge {
    long long val;
    long long dest;
    long long worth;
} G[100003];

struct EdgeUtil {
    inline void add(const Edge& e) {
        G[edgeCounter++] = e;
    }
} U;

long long n, a, b, c;
int edgeCounter = 0;

int dfs(int current, int father) {
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int t = 0; t < n - 1; t++) {
        cin >> a >> b >> c;
        U.add({a, b, c});
        U.add({b, a, c});
    }
    dfs(0, 0);
    return 0;
}