#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 100001

int N, M, C;
long long cow[MAXN], firstArrival[MAXN];

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N >> M >> C;
    for(int t = 0; t < N; t++) cin >> cow[t];
    sort(cow, cow + N);
    for(int t = 0; t < N; t++) {
        //busAssigned[t] = t % C;
        if(!firstArrival[t / C]) firstArrival[t / C] = cow[t];
    }
    cout << cow[N - 1] - firstArrival[M - 1] << endl;
    // cout << cow[N - 1] - cow[N - 1 - (N - 1) % C] << endl;
    return 0;
}