#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10001],n,ans=0;
// http://blog.csdn.net/BeNoble_/article/details/53976434
int main() {
	freopen("testdata.in","r",stdin);
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
	/* Old
	for(int t=0;t<n;t++) cin>>a[t];
	sort(a,a+n);
	ans=a[0]+a[1];
	for(int t=2;t<n;t++) {
		//clog<<"n: "<<n<<"   "<<"t: "<<t<<"   "<<"a[t]: "<<a[t]<<"   "<<"a[t+1]: "<<a[t+1]<<"   "<<"n-t-1: "<<n-t-1<<endl;
		//ans+=(n-t-1)*(a[t]+a[t+1]);
		ans+=a[t];
	}
	cout<<ans<<endl;
	*/
	return 0;
}
