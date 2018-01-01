// Medic
#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;
int n,v[101],w[101],V,f[1001];
int main() {
    ios::sync_with_stdio(false);
    memset(v,0,sizeof(v));
    memset(w,0,sizeof(w));
    memset(f,0,sizeof(f));
    cin>>V>>n;
    for(int t=1;t<=n;t++) {
        cin>>v[t]>>w[t];
    } 
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[V]<<endl;
}
