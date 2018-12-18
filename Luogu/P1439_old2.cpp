#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 500003

int N, M, S;
int fa[MAXN];
bool visa[MAXN];


void makeTagA(int n) {
    if(visa[n]) return;
    if(n == fa[n]) {
        visa[n] = true;
        return;
    }
    visa[n] = true;
    makeTagA(fa[n]);
}

int makeTagB(int n) {
    if(n == fa[n] || visa[n]) {
        return n;
    }
    return makeTagB(fa[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> S;
    fa[S] = S;
    for(int t = 0; t < N; t++) {
        int x, y;
        cin >> x >> y;
        fa[x] = y;
        fa[y] = x;
    }
    for(int t = 0; t < M; t++) {
        memset(visa, 0, sizeof(visa));
        int a, b;
        cin >> a >> b;
        makeTagA(a);
        cout << makeTagB(b) << endl;
    }
    return 0;
}