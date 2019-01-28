#include <iostream>
using namespace std;

#define MAXN 100001
#define lson(x) x << 1
#define rson(x) x << 1 | 1
typedef unsigned long long ull;

int N;
ull V[MAXN], d[MAXN];

int merge(int x, int y) {
    if(!x | !y) return x + y;
    if(V[x] > V[y]) swap(x, y);
    rson[x] = merge(rson[x], y);
    if(d[lson[x]] < d[rson[x]]) swap(lson[x], rson[x]);
    d[x] = d[rson[x]] + 1;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    return 0;
}