// need to continue
#include <iostream>
#include <vector>
using namespace std;
vector<string> path;
int m,n,sx,sy,ex,ey;
bool a[16][16];
int d[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
bool vis[10000];
/*void dfs(int now) {
    if(now==n+1){check();return;}
    for(int i=1;i<=20;i++){
        if(vis[i]) continue;
        a[now]=i; vis[i]=1;
        dfs(now+1);
        vis[i]=0;
    }
}*/
void out() {
	for(int t=0;t<path.size();t++) {
		cout<<"("<<path.back()<<")";
		if(t!=path.size()-1) cout<<"->";
	}
	path.clear();
}
void dfs(int now,int x,int y) {
	if(x==ex&&y==ey) {
		path.push_back(x+","+y);
		out();
		return;
	}
	for(int t=0;t<m;t++) {
		dfs(now+1,t,y+1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>a[i][j];
	cin>>sx>>sy>>ex>>ey;
	
}
