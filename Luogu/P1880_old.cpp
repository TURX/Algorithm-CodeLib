#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;
int N,arr[108],f[108][108];
void getMin();
void getMax();
int main() {
	ios::sync_with_stdio(false);
	cin>>N;
	for(int t=1;t<=N;t++) {
		cin>>arr[t];
		arr[t]+=arr[t-1];
	}
	getMin();
	getMax();
}
void getMin() {
	memset(f,127/3,sizeof(f));
	for(int i=1;i<=N;i++) f[i][i]=0;
	for(int i=N-1;i>=1;i--) {
		for(int j=i+1;j<=N;j++) {
			for(int k=i;k<j;k++) {
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+arr[j]-arr[i-1]);
			}
		}
	}
	cout<<f[1][N]<<endl;
}
void getMax() {
	memset(f,0,sizeof(f));
	for(int i=N-1;i>=1;i--) {
		for(int j=i+1;j<=N;j++) {
			for(int k=i;k<j;k++) {
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+arr[j]-arr[i-1]);
			}
		}
	}
	cout<<f[1][N]<<endl;
}
