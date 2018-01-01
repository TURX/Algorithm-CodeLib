#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
string al,bl;
int a[512],b[512],c[512],lena,lenb,lenc,i,x;
int main() {
	ios::sync_with_stdio(false);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cin>>al>>bl;
    lena=al.length();
    lenb=bl.length();
    for(i=0;i<=lena-1;i++) a[lena-i]=al[i]-48;
    for(i=0;i<=lenb-1;i++) b[lenb-i]=bl[i]-48;
    lenc=max(lena,lenb);
    x=0;
    while(lenc>=lena||lenc>=lenb) {
        c[lenc]=a[lenc]-b[lenc]-x;
        x=c[lenc]/10;
        c[lenc]%=10;
        lenc--;
    }
    c[lenc]=x;
    if(c[lenc]==0) lenc--;
    for(i=lenc;i>=1;i--) cout<<c[i];
    cout<<endl;
    return 0;
}
