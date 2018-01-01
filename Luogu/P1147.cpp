#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int target;
/*int v_plus() {
	int result=0;
	for(int t=0;t<v.size();t++) result+=v[t];
	return result;
}*/ 
int main() {
	ios::sync_with_stdio(false);
	cin>>target;
	for(int i=1;i<=target/2;i++) {
		int sum=0; 
		for(int j=i;j<=target-i;j++) {
			v.push_back(j);
			sum+=j;
			if(sum>=target) break;
		}
		if(sum==target) cout<<v[0]<<" "<<v[v.size()-1]<<endl;
		v.clear();
	}
	return 0;
}
