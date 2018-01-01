#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n,a,b;
struct person {
	int left;
	int right;
	friend bool operator<(person l, person r) {
		return l.left/l.right>r.left/r.right;
	}
};
person make(int l,int r) {
	person temp;
	temp.left=l;
	temp.right=r;
	return temp;
}
priority_queue<person> pq;
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>a>>b;
	for(int t=0,l,r;t<n;t++) {
		cin>>l>>r;
		pq.push(make(l,r));
	}
	while(!pq.empty()) {
		person temp=pq.top();
		pq.pop();
		cout<<temp.left<<" "<<temp.right<<endl;
	}
	return 0;
}
