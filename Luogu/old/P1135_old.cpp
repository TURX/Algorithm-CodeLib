#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int N,A,B,K[207],answer=400;
bool status[207];
bool check(int k,int now,bool operation) {
	if(operation==false) return now-k<0;
	if(operation==true) return now+k>=N;
}
void dfs(int floor,int button_time) {
	if(floor+1==B) {
		if(answer!=-1) answer=min(answer,button_time); else answer=button_time;	
		return;
	}
	if(button_time>answer) return;
	status[floor]=true;
	if(check(K[floor],floor,false)&&!status[floor]) dfs(K[floor]-floor,button_time++);
	if(check(K[floor],floor,true)&&!status[floor]) dfs(K[floor]+floor,button_time++); 
	status[floor]=false;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>N>>A>>B;
	for(int t=0;t<N;t++) cin>>K[t];
	dfs(A-1,0);
	if(answer==400) {
		cout<<-1<<endl;
		return 0;
	}
	cout<<answer<<endl;
	return 0;
}
