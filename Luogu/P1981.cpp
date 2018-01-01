#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
string expr,a,b;
int calc=0;
bool first=true;
void outans() {
	int l=atoi(a.c_str()),r=atoi(b.c_str());
	if(calc==1) b=l+r;
	if(calc==2) b=l*r;
	a=b;
	b.clear();
	cout<<"[LOG] "<<a<<endl;
}
void readb() {
	while(!expr.empty()||expr.back()=='+'||expr.back()=='*')
		b.push_back(expr.back());
}
int main() {
	cin>>expr;
	while(!expr.empty()) {
		if(expr.back()=='+') {
			first==false;
			calc=1;
			expr.pop_back();
			readb();
			outans();
		}
		if(expr.back()=='*') {
			first==false;
			calc=2;
			expr.pop_back();
			readb();
			outans();
		}
		if(first==true) {
			a.push_back(expr.back());
			expr.pop_back();
		}
	}
} 
