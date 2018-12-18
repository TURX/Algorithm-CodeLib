#include <iostream>
using namespace std;
int n,ans[14];
long long s;
struct position {
	int x,y;
};
inline position make_pos(int x,int y) {
	position pos;
	pos.x=x; pos.y=y;
	return pos;
}
inline bool check(position pos) {
	for(int t=0;t<=n;t++) if(ans[t]==pos.y||(t+ans[t])==(pos.x+pos.y)||(t-ans[t])==(pos.x-pos.y)) return false;
	return true;
}
inline void find(int layer) {
	if(layer>n) {
		s++;
		if(s<4) {
			for(int t=1;t<=n;++t) cout<<ans[t]<<" ";
		}
		return;
	}
	for(int t=1;t<=n;t++)
		if(check(make_pos(layer,t))) {
			ans[layer]=t;
			find(t+1);
			ans[t]=0;
		}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	find(1);
	cout<<s<<endl;
	return 0;
}
