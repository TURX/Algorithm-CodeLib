#include <iostream>
using namespace std;

#define MAXN 200003

int N, tmp, minDis = 0x7FFFFFFF;

struct UFSET {
    int fa[MAXN], d[MAXN];
    inline void init(int n) {
        while(n--) fa[n] = n;
    }
    inline int find(int n) {
        if(fa[n] == n) return n;
        int last = fa[n];
        fa[n] = find(fa[n]);
        d[n] += d[last];
        return fa[n];
    }
    inline void merge(int a, int b) {
        int x = find(a), y = find(b);
        if(x != y) {
            fa[x] = y;
            d[a] = d[b] + 1;
        } else {
            minDis = min(minDis, d[a] + d[b] + 1);
        }
    }
} U;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    U.init(N);
    for(int t = 1; t <= N; t++) {
        cin >> tmp;
        U.merge(t, tmp);
    }
    cout << minDis << endl;
    return 0;
}