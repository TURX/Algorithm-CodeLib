#include <iostream>
#include <cstdio>
using namespace std;
int a[10000][10000], maxN=0, n;

int main() {
    // freopen("secret/sample/P1216/yl.in","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for(register int i=1;i<=n;i++) {
        for(register int j=1;j<=i;j++) {
            cin >> a[i][j];
            a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
            maxN=max(a[i][j],maxN);
            // f[i][j]=a[i][j];
        }
    }
    /*
    for(register int i=1;i<=n;i++) {
        for(register int j=i;j<=i;j++) {
            f[i][j]=max(f[i+1][j],f[i+1][j+1]+a[i][j]);
        }
    }
    cout << f[1][1] << endl;
    */
    cout << maxN << endl;
    return 0;
}