%:pragma GCC optimize(2)
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std; 
string a,b,r;
bool first=true;
bool carry=false;
int cvt_c(char target) {
	return target-'0';
}
char cvt_i(int target) {
	return target+'0';
}
void trans(string& a,string& b) {
	string wait_back;
	if(a.length()==b.length()) return;
	long long aLen=a.length(),bLen=b.length(),maxLen=max(aLen,bLen),remain;
	bool selection=false;
	if(maxLen==bLen) selection=true;
	if(selection==false) {
		remain=aLen-bLen;
		for(int t=0;t<remain;t++) wait_back.push_back('0');
		wait_back+=b;
		b=wait_back;
	} else {
		remain=bLen-aLen;
		for(int t=0;t<remain;t++) wait_back.push_back('0');
		wait_back+=a;
		a=wait_back;
	}
}
char getAns(char l,char r) {
	int ans=cvt_c(a.back())-cvt_c(b.back());
	if(carry==true) {
		carry=false;
		ans-=1;
	}
	if(ans<0) {
		carry=true;
		ans+=10; 
	}
	return cvt_i(ans); 
}
int main() {
	ios::sync_with_stdio(false);
	cin>>a>>b;
	if(a==b) {
		cout<<'0'<<endl;
		return 0;
	}
	if(a<b&&a.size()==b.size()||a.size()<b.size()) {
		cout<<'-';
		swap(a,b);
	}
	trans(a,b);
	while(!b.empty()) {
		r.push_back(getAns(a.back(),b.back()));
		a.pop_back(); b.pop_back();
	}
	while(!r.empty()) {
		if(first&&r.back()=='0') {
			getAns(a.back(),b.back());
			continue;
		}
		if(first&&r.back()!='0') first=false;
		if(isdigit(r.back())) cout<<r.back();
		r.pop_back();
	}
	cout<<endl;
}
