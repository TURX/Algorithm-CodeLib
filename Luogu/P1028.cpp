#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n;
int solve(int i)
{
	if ((i==0)||(i==1)) return 1;
	else return (solve(i-2)+solve(i/2));
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	cout<<solve(n)<<endl;
}
