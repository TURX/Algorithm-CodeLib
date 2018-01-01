#include <iostream>
#include <cmath>
using namespace std;
int n;
unsigned long long fib[50],res,m=pow(2,31);
inline unsigned long long f(int n) {
	if(fib[n]) return fib[n];
	return (f(n-1)+f(n-2))%m;
}
inline bool prime(unsigned long long a) {
	for(unsigned long long k=2;k<=sqrt(a);++k)
		if(a%k==0) return false;
	return true;
}
inline void divide(unsigned long long num) {
	if(num==1||num==2) {
		cout<<1<<endl;
		return;
	}
	for(unsigned long long y=2;num>1;) {
		if(num%y==0) {
			cout<<y;
			if(num/y!=1) cout<<"*";
			num/=y;
		} else y++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	fib[1]=1; fib[2]=1; fib[48]=512559680;
	res=f(n);
	cout<<res<<"=";
	divide(res);
	cout<<endl;
	return 0;
}
