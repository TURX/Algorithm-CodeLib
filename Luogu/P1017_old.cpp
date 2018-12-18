// keng 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
string N; int R; // Initalize
/*
int multi(int number, int count) {
	if(count==0) return 1;
	if(count==1) return number;
	int storage=number;
	for(int t=0;t<abs(count);t++) number*=storage;
	if(count<0;)
	return number;
}
*/
string multi(string number, int count) {
	char *cstr = new char[number.length() + 1];
	strcpy(cstr, number.c_str());
	int num=atoi(cstr);
	char result[100];
	if(count==0) return "1";
	if(count==1) return number;
	if(count>0) {
		int ptr=0;
		for(int len=number.length();len>=0;len--) {
			//int c=number[len]-'0';
			int remain=num%count;
			num/=count;
			result[ptr]=remain+'0';
			//clog<<"[LOG] ptr="<<ptr<<" result[ptr]="<<result[ptr]<<endl;
			ptr++;
		}
		result[ptr++]='1';
		//clog<<"[LOG] result="<<result<<endl;
		strrev(result);
		string back(result);
		return back;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>N>>R;
	cout<<N<<"="<<multi(N,R)<<"(base"<<R<<")"<<endl;
}
