#include<iostream>
using namespace std;
string as,bs;
unsigned short int a[512],b[512],c[512];
int lenans=1,carry=0;
int main() {
	ios::sync_with_stdio(false);
	cin>>as>>bs;
	for(int t=0;t<as.length();t++) a[t]=as[t]-48;
	for(int t=0;t<bs.length();t++) b[t]=bs[t]-48;
	for(;lenans<=as.length()||lenans<=bs.length();lenans++) {
		c[lenans]=a[lenans]+b[lenans]+carry;
		carry=c[lenans]/10;
		c[lenans]%=10;
	}
	c[lenans]=carry;
	if(c[lenans]==0) lenans--;
	for(int t=lenans;t>=0;t--) cout<<c[t];
	cout<<endl;
}
