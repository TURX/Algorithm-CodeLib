%:pragma GCC optimize(2)
#include <iostream>
#include <memory.h>
using namespace std;
int n,m,z,x,y,arr[10000],rank[10000],midresult;
void makeSet(int n) {
	for(int t=1;t<=10000;t++) arr[t]=t;
}
int checkSet(int x) {
	if(arr[x]==x) return x;
	else return arr[x]=checkSet(arr[x]);
}
void mergeSet(int x,int y) {
	if(checkSet(x)==checkSet(y)) return;
	arr[checkSet(y)]=checkSet(x);
}
int main() {
	ios::sync_with_stdio(false);
	memset(arr,0,sizeof(arr));
	cin>>n>>m;
	makeSet(n);
	for(int t=0;t<m;t++) {
		cin>>z>>x>>y;
		if(z==1) mergeSet(x,y);
		if(z==2) {
			if(checkSet(x)==checkSet(y)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
	return 0;
}
