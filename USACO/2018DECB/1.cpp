#include <cstdio>
#include <iostream>
using namespace std;

unsigned long long milk[3], capacity[3];

inline void transfer(int u, int v) {
    if(capacity[v] < milk[u] + milk[v]) {
        milk[u] += milk[v] - capacity[v];
        milk[v] = capacity[v];
    } else {
        milk[v] += milk[u];
        milk[u] = 0;
    }
}

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    ios::sync_with_stdio(false);
    for(int t = 0; t < 3; t++) cin >> capacity[t] >> milk[t];
    for(int t = 0; t < 100; t++) {
        switch(t % 3) {
            case 0: // From 0 to 1
                transfer(0, 1);
                break;
            case 1: // From 1 to 2
                transfer(1, 2);
                break;
            case 2: // From 2 to 0
                transfer(2, 0);
                break;
        }
    }
    for(int t = 0; t < 3; t++) cout << milk[t] << endl;
    return 0;
}