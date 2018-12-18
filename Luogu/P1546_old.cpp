// Prim Template: Wire

#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 103

int N, g[MAXN][MAXN], tot, ans[MAXN];
bool onTree[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> g[i][j];
        }
    }
    // memset(ans, INT32_MIN, sizeof(ans));
    ans[1] = 0;
    for(int i = 1; i <= N; i++) {
        int k = 0;
        for(int j = 1; j <= N; j++) {
            if(!onTree[j] && ans[j] < ans[k]) k = j;
        }
        onTree[k] = true;
        for(int j = 1; j <= N; j++) {
            if(!onTree[j] && g[k][j] < ans[j]) {
                ans[j] = g[k][j];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        tot += ans[i];
    }
    cout << tot << endl;
    return 0;
}