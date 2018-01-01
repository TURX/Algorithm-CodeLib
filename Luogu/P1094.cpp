#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int w,n,p[30001],group=0,l=1,r;
int main() {
	//freopen("in.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>w>>n;
	r=n;
	for(int t=1;t<=n;t++) cin>>p[t];
	sort(p+1,p+n+1);
	while(l<=r) // 2 Divide
    {
    	if(l==r) {
    		group++;
    		break;
		}
        if(p[l]+p[r]<=w)
          l++,r--,group++;
        else
          r--,group++;
    }
	cout<<group<<endl;
}
