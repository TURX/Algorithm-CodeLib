#include <iostream>
#include <bits/extc++.h>
using namespace std;
typedef unsigned long long LLL;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(LLL i = 0; i <= n; i++) {
        for(LLL j = 0; j <= m; j++)
    }
    //dp[i][j]=max{dp[i+1][j]+2^(m-(j-i))×v[i],dp[i][j-1]+2^(m-(j-i))×v[j]}
}