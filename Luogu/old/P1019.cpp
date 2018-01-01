// I am raji, cannot AC this test
#include<iostream>
#include<string>
using namespace std;

string refl(string str) {
	for(int i = 0; i <= str.length()/2; ++i) {
		char c = str[i];
		str[i] = str[str.length() - i -1];
		str[str.length() - i - 1] = c;
	}
	return str;
}
void rd(string& a,string& b) {
	int len=min(a.length(),b.length()),rm=0,lena=a.length();
	string ta,tb;
	for(int t=0;t<len;t++) {
		ta+=a[a.length()-t-1];
		tb+=b[t];
		if(refl(ta)==tb) rm=t+1;
	}
	cout<<"[LOG] rm="<<rm<<endl; 
	if(rm!=0) for(int t=lena;t>lena-rm;t--) a.erase(a.end()-1);
}
int main() {
	ios::sync_with_stdio(false);
	string a;
	string b;
	cin>>a>>b;
	rd(a,b);
	
	cout<<a<<b<<endl;
}
