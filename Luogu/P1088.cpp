#include<iostream>
#include<algorithm>
using namespace std;
int n,m,arr[10005];
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int t=0;t<n;t++) cin>>arr[t];
	while(m!=0) {
		m--;
		next_permutation(arr,arr+n);
	}
	for(int t=0;t<n-1;t++) cout<<arr[t]<<" ";
	cout<<arr[n-1]<<endl;
	return 0;
}
