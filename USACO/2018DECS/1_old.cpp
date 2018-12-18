#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 10001

int N, M, C, cnt;
long long cow[MAXN], delay[MAXN];

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N >> M >> C;
    for(int t = 0; t < N; t++) {
        cin >> cow[t];
    }
    sort(cow, cow + N);
    int last = 0;
    for(int i = 0; i < M; i++) {
        last = cow[cnt + C - 1];
        for(int j = 0; j < C; j++) {
            delay[cnt] = last - cow[cnt];
            cnt++;
        }
    }
    int r = N - C + N % C;
    cout << delay[r] << endl;
    return 0;
}