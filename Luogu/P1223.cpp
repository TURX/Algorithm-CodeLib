#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
struct data {
	int num;
	long double time;
} d[1000];
long double ans=0;
bool cmp(data lhs, data rhs)
{
    if (lhs.time != rhs.time)
		return lhs.time < rhs.time;
    else                  
		return lhs.num < rhs.num;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int t=0;t<n;t++) {
		cin>>d[t].time;
		d[t].num=t+1;
	}
	sort(d,d+n,cmp);
	for(int t=0;t<n;t++) {
		cout<<d[t].num<<" ";
		ans+=d[t].time*(n-t-1);
	}
	cout<<endl;
	//for(int t=0;t<n;t++) {
	//	ans+=d[t].time;
	//	d[t].time=ans;
	//}
	//for(int t=0;t<n;t++) cout<<d[t].time<<" ";
	//cout<<endl;
	//ans=0;
	//for(int t=0;t<n;t++) ans+=d[t].time;
	ans/=n;
	printf("%.2Lf\n",ans);
}
