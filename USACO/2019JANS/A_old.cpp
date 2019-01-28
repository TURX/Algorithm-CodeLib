#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int N, a, b, ans;
//map<unsigned long long, map<unsigned long long, bool> > G;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 0; t < N - 1; t++) {
        cin >> a >> b;
        if(abs(a - b) == 1) ans++;
        //G[a][b] = 1, G[b][a] = 1; // Bidirectional
    }
    /*
    for(unsigned long long i = 1; i <= N; i++) {
        for(unsigned long long j = i + 1; j <= N; j++) {
            if(!G[i][j]) ans++;
        }
    }
    */
    cout << ans << endl;
    return 0;
}