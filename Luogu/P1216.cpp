#include<iostream>
#include<cmath>
using namespace std;
int r,a[1005][1005],f[1005][1005];
int main() {
	ios::sync_with_stdio(false);
	cin>>r;
	for(int t1=1;t1<=r;t1++) for(int t2=1;t2<=t1;t2++) cin>>a[t1][t2];
	f[1][1]=a[1][1];
	for(int t1=2;t1<=r;t1++) for(int t2=1;t2<=r;t2++) f[t1][t2]=max(f[t1-1][t2-1],f[t1-1][t2])+a[t1][t2];
	int ans=0;
	for(int t=1;t<=r;t++) ans=max(ans,f[r][t]);
	cout<<ans<<endl;
}
