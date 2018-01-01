#include<iostream>
using namespace std;
int N,K,record[100000];

int solve(int n) {
	if(record[n]) return record[n];
	if(n==0||n==1) return 1;
	int ans=0;
	for(int t=1;t<=K;t++) if(n-t>=0) ans=(solve(n-t)+ans)%100003;
	record[n]=ans;
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>N>>K;
	record[0]=1;
	record[1]=1;
	cout<<solve(N)<<endl;
}
