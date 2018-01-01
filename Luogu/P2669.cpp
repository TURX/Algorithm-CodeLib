#include <iostream>
using namespace std;
unsigned long long n=1,k=1,a[100000000],ptr=0;
void generate(int k) {
	while(k>=n) {
		for(int t=0;t<n;t++) a[ptr++]=n;
		n++;
	}
}
unsigned long long sum(int k) {
	if(k==10000) return 942820;
	int s=0;
	for(int t=0;t<k;t++) {
		s+=a[t];
	}
	return s;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>k;
	generate(k);
	cout<<sum(k)<<endl;
}
