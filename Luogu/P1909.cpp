#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,cost,mincost=0x7ffffff,t,cnt; 
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(t=0;t<3;t++) {
		cin>>cnt>>cost;
		cost*=std::ceil(n*1.0/cnt);
		mincost=min(mincost,cost);
	} 
	cout<<mincost<<endl;
}
