#include <iostream>
using namespace std;
long long a,b,rec[100000007],results=0;
long long fib(long long n) {
	if(rec[n]) return rec[n];
	return fib(n-1)+fib(n-2);
}
int main() {
	long long n;
	cin>>n;
	rec[1]=1; rec[2]=2;
	
	cout<<fib(n)<<endl;
	return 0;
}
