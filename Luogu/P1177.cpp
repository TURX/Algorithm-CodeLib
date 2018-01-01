#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
long long a[100000];
int main() {
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	for(int t=0;t<n;t++) cin>>a[t];
	sort(a,a+n);
	for(int t=0;t<n;t++) cout<<a[t]<<" ";
	cout<<endl;
	return 0;
}
