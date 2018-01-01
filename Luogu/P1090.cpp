%:pragma GCC optimize(2)
#include <iostream>
#include <vector>
#include <queue>
//#include <algorithm>
using namespace std;
int n,strength=0;
priority_queue<int, vector<int>, greater<int> > pq;
int fruit[10008];
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int t=0,in;t<n;t++) {
		cin>>in;
		pq.push(in);
	}
	//for(int t=n,out;t>=1;t--) {
	while(!pq.empty()) {
		int out;
		out=pq.top();
		pq.pop();
		if(pq.empty()) break;
		out+=pq.top();
		strength+=out;
		pq.pop();
        pq.push(out);
    }
	cout<<strength<<endl;
	return 0;
}
