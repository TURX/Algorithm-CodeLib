#include <iostream>
#include <cmath>
using namespace std;
int n, V, f[10000001], m, v, w;
int main() {
    ios::sync_with_stdio(false);
    cin >> V >> n;
    /*for(int t = 1; t <= n; t++) {
        cin >> w[t] >> v[t];
    }*/
    for(int i = 1; i <= n; i++) {
        cin >> w >> v;
        for(int j = w; j <= V; j++) {
            f[j] = max(f[j], f[j - w] + v);
        }
    }
    cout << f[V] << endl;
    return 0;
}
