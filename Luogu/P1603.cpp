#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <queue>
#include <map>
#include <cctype>
#include <cstdlib>
using namespace std;
string s;
map<string,int> m;
priority_queue<int> an;
ostringstream ous;
char num[3];
inline void initalize() {
	m["one"] = m["first"] = m["a"] = m["another"] = 1;
	m["two"] = m["second"] = m["both"] = 2;
	m["three"] = m["third"] = 3;
	m["four"] = 4;
	m["five"] = 5;
	m["six"] = 6;
	m["seven"] = 7;
	m["eight"] = 8;
	m["nine"] = 9;
	m["ten"] = 10;
	m["eleven"] = 11;
	m["twelve"] = 12;
	m["thirteen"] = 13;
	m["fourteen"] = 14;
	m["fifteen"] = 15;
	m["sixteen"] = 16;
	m["seventeen"] = 17;
	m["eighteen"] = 18;
	m["nineteen"] = 19;
	m["twenty"] = 20;
}
char* getLower(string t) {
	for(int i=0;i<t.length();i++) {
		t[i]=tolower(t[i]);
	}
}
int main() {
	initalize();
	while(cin>>s&&s!=".") {
		getLower(s);
		an.push(m[s]*m[s]%100);
	}
	if(an.empty()) {
		cout<<"0"<<endl;
		return 0;
	}
	for(int it:an) {
		sprintf(num, "%02d", it);
		ous<<num;
	}
	printf("%lld\n",atoll(ous.str().c_str()));
	return 0;
} 
