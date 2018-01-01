#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long a[10001],n,ans=0;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int t=1;t<=n;t++) scanf("%d",&a[t]);
	sort(a+1,a+n+1);
	for(int t=1,s;t<=n-1;t++) {
		a[t+1]+=a[t];
		ans+=a[t+1];
		s=t+1;
		while(t<n&&a[t]>a[t+1]) swap(a[t],a[t+1]),t++;
	}
	cout<<ans<<endl;
	return 0;
}
