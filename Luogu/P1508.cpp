#include <iostream>
#include <cmath>
using namespace std;
int m,n,matrix[203][203],dp[203][203],direction[2]={-1,1};
void dpf(int x,int y) {
	if(x==1) {
		dp[x][y]=matrix[x][y];
		return;
	}
	if(dp[x][y]!=0) return;
	for(int t=0;t<2;t++) {
		if(y+direction[t]<1&&y+direction[t]>n) continue;
		dpf(x+direction[t],y-1);
		dp[x][y]=max(dp[x][y],dp[x-1][y+direction[t]]+matrix[x][y]);
	}
	return;
	//f[x][y]=max(f[x][y],f[x-1][y+i]+a[x][y]);
}
int main() {
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			cin>>matrix[i][j];
		}
	}
	dpf(m,n/2+1);
	dpf(m,n/2);
	dpf(m,n/2+2);
	cout<<max(max(dp[m][n/2],dp[m ][n/2+1]),dp[m][n/2+2])<<endl;
}
