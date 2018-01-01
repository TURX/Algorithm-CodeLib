#include <iostream>
#include <string>
using namespace std;
int dp[10000][10000],n;
int a[100000],b[100000];
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int t=0;t<n;t++) cin>>a[t];
	for(int t=0;t<n;t++) cin>>b[t];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(a[i+1]==b[j+1]) dp[i+1][j+1]=dp[i][j]+1;
			else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}
	}
	cout<<dp[n-1][n-1]<<endl;
}
