#include<iostream>
#include<algorithm>
using namespace std;
int a[100];
int b[100];
int main() {
	ios::sync_with_stdio(false);
	int an,bn=0;
	cin>>an;
	for(int t=0;t<an;t++) cin>>a[t];
	sort(a,a+an);
	for(int t=0;t<an;t++) {
		if(a[t]==a[t+1]) continue;
		else {
			b[bn]=a[t];
			bn++;
		}
	}
	cout<<bn<<endl;
	for(int t=0;t<bn;t++) {
		cout<<b[t]<<" ";
	}
	cout<<endl;
	return 0;
}
