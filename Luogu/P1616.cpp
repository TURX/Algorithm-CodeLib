%:pragma GCC optimize(2)
#include <iostream>
#include <cmath>
using namespace std;
int n,v[10001],w[10001],V,f[10001][10001];
int main() {
    ios::sync_with_stdio(false);
    cin>>V>>n;
    for(int t=1;t<=n;t++) {
        cin>>w[t]>>v[t];
    } 
    for(int t=0;t<=V;t++) f[0][t]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=V;j++){
        	f[i][j]=0;
        	for(int k=0;k<=j/w[i];k++)
        		f[i][j]=max(f[i][j],f[i-1][j-k*w[i]]+k*v[i]);
        }
    }
    cout<<f[n][V]<<endl;
}
