#include <iostream>
#include <cstring>
using namespace std;

int g[101][101];
int minn[101];
bool u[101];

int n, i, j;
int main() {
    cin >> n;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    memset(minn, 0x7f, sizeof(minn));
    minn[1] = 0;
    memset(u, 1, sizeof(u));
    for(i = 1; i <= n; i++) {
        int k = 0;
        for(j = 1; j <= n; j++) if(u[j] && (minn[j] < minn[k])) k = j;
        u[k] = false;
            for(j = 1; j <= n; j++) if(u[j] && (g[k][j] < minn[j])) minn[j] = g[k][j];
    }
    int total = 0;
        for(i = 1; i <= n; i++) total += minn[i];
        cout << total << endl;
        return 0;
}