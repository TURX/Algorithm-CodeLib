// Librarian
// TURX
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > pq,tq;
long long in,im;
long long n,q;
bool checkExist(long long a,long long b) {
	long long p=8;
	long long miduse;
	while(a!=0) {
		if(a==b) return true;
		miduse=pow(10,p--);
		a%=miduse;
	}
	return false;
}
long long findFirst(long long target) {
	tq=pq;
	while(!tq.empty()) {
		long long getN=tq.top();
		if(checkExist(getN,target)) {
			return getN;
		}
		tq.pop();
	}
	return -1;
}
int main() {
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(long long t=0;t<n;t++) {
		cin>>in;
		pq.push(in);
	}
	for(long long t=0;t<q;t++) {
		cin>>in>>im;
		cout<<findFirst(im)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
