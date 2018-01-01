#include<iostream>
#include<cmath>
using namespace std;
int n,m,v[25],w[25],f[30000];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int t=0;t<m;t++) cin>>v[t]>>w[t];
    for (int i=0;i<m;i++)
    for (int j=n;j>=v[i];j--)
    if (f[j-v[i]]+w[i]*v[i]>f[j])
        f[j]=f[j-v[i]]+w[i]*v[i];
    cout<<f[n]<<endl;
    return 0;
}
