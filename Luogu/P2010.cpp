#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
char date[8],endate[8];
int mon2day[12]={31,29,31,30,31,30,31,31,30,31,30,31},cntdate=0;
bool checkMirror(char n[8]) {
	char compareStr[8];
	for(int t=0;t<8;t++) compareStr[t]=n[t];
	for(int t=4;t>=0;t--) {
		swap(compareStr[t],compareStr[7-t]);
	}
	if(compareStr==n) return true; else return false;
}
/*bool checkLeapYear(int year) {
	bool isLeap=false;
	if(year%4==0&&year%100!=0) isLeap=true;
	if(year%400==0) isLeap=true;
	return isLeap;
}*/
bool check(char n[8]) {
	char month[2]={n[4],n[5]},day[2]={n[6],n[7]};
	if(atoi(month)<=12) {
		if(atoi(day)<=mon2day[atoi(month)]) return true;
	}
	return false;
}
void addate() {
	char curdate[8];
	for(int t=0;t<8;t++) curdate[t]=date[t];
	char day[2]={date[6],date[7]}; int curday=atoi(day)+1; curdate[7]=curday/10; curdate[8]=curday%10;
	if(check(curdate)) return; else {
		curdate[7]='0'; curdate[8]='1';
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>date;
	cout<<date<<endl;
	while(date<=endate) {
		addate();
		if(checkMirror(date)) cntdate++;
	}
	cout<<cntdate<<endl;
}
