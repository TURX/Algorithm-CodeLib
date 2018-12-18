#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
//#define MAXN 500003

//LL N, color[MAXN], sum = 1;
LL N, tmp, sum = 1;

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N;
    for(LL t = 0; t < N; t++) {
        cin >> tmp;
        sum *= tmp;
    }
    cout << sum << endl;
    return 0;
}