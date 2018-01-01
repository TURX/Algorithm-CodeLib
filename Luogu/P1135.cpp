#include <iostream>
#include <algorithm>
using namespace std;
int N,A,B,K[207],answer=10000;
bool status[207];
void dfs(int floor,int button_time) {
	if(floor==B-1) {
		answer=min(answer,button_time);
		return;
	}
	if(button_time>answer) return;
	status[floor]=true;
	if(floor+K[floor]<=N-1&&!status[floor+K[floor]]) dfs(K[floor]+floor,button_time+1);
	if(floor-K[floor]>=0&&!status[floor-K[floor]]) dfs(floor-K[floor],button_time+1);
	status[floor]=false;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>N>>A>>B;
	for(int t=0;t<N;t++) cin>>K[t];
	status[A-1]=true;
	dfs(A-1,0);
	if(answer==10000) {
		cout<<-1<<endl;
		return 0;
	} else cout<<answer<<endl;
	return 0;
}
