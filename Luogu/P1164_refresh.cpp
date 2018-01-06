#include <iostream>
#include <cstdio>
using namespace std;
int n, m, a[103], f[103][103];
int main() {
    cin >> n >> m;
    for(int t=0;t<n;t++) cin >> a[t];
    for(int i=1;i<n;i++) {
        for(int j=1;j<i;j++) {
            f[i][j]+=max(f[i-1][j-1])
        }
    }
    return 0;
}