#include <iostream>
using namespace std;
bool map[508][508],record[508][508];
bool nex[2][2]={{1,0},{0,1}};
int N,M,Q,a,b,c,d,siz;
bool flag=false;
bool dfs(int x,int y,int n) {
	if(x==c&&y==d) {
		flag=true;
		return true;
	}
	if(n>siz) return false;
	for(int t=x;t<N;t++) {
		if(record[x][y]==true) continue;
		record[x][y]=true;
		dfs(x,y+1,n+1);
		record[x][y]=false;
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin>>N>>M;
	siz=N*M;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>map[N][M];
		}
	}
	cin>>Q;
	for(int t=0;t<Q;t++) {
		cin>>a>>b>>c>>d;
		dfs(a,b,1);
		if(flag==true) {
			flag=false;
			cout<<"Safe"<<endl;
		} else {
			cout<<"Dangerous"<<endl;
		}
	}
}
