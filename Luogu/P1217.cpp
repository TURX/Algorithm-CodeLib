#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int a,b;
bool prime() {
	for(int k=2;k<=sqrt(a);++k)
	if(a%k==0) return false;
	return true;
}
bool check() {
	if(!prime()) return false;
	char str[100]; /*long long num=a; int strptr=0;
	while(!num/10<1) {
		str[strptr]=num/10;
		strptr++;
	}*/
	itoa(a,str,10);
	int len=strlen(str);
	//cout<<"[LOG] str="<<str<<endl;
	if(len==1) return true;
	for(int t=0;t<len/2;t++) {
		if(str[t]!=str[len-t-1]) return false;
	}
}
int main() {
	//freopen("P1217_OUTPUT.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin>>a>>b;
	for(;a<=b;a++) {
		if(check()) {
			cout<<a<<endl;
		}
	}
	return 0;
}
