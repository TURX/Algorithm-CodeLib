#include <iostream>
#include <algorithm>
using namespace std;
int N,A,B,K[207],answer=400;
bool status[207];
void dfs(int floor,int button_time) {
	if(floor==B) answer=min(answer,button_time);
	//if(button_time>answer) return;
	status[floor]=true;
	if(floor+K[floor]<=N&&!status[floor+K[floor]]) dfs(floor+K[floor],button_time+1);
	if(floor-K[floor]>=1&&!status[floor-K[floor]]) dfs(floor-K[floor],button_time+1);
	status[floor]=false;
}
int main()
{
    ios::sync_with_stdio(false);
	cin>>N>>A>>B;
	for(int t=1;t<N;t++) cin>>K[t];
	status[A]=true;
	dfs(A,0);
	if(answer==400) {
		cout<<-1<<endl;
		return 0;
	}
	cout<<answer<<endl;
	return 0;
}
