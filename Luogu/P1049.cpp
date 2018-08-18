#include <iostream>
using namespace std;

int V, n, v[31], f[20010];

int main()
{
    cin >> V >> n;
    for(int t = 0; t < n; t++) {
        cin >> v[t];
    }
    for(int i = 0; i < n; i++) {
        for(int j = V; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + v[i]);
        }
    }
    cout << V - f[V] << endl;
    return 0;
}
