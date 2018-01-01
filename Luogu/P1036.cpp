// abolished

#include<iostream>
using namespace std;
int n,k,ptr[20],x[20],graph[20][5000000],record[20][5000000],ans=0;
struct position{
	int x;
	int y;
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
};
bool prime(int n){
    if(n==1||n==0) return 0;
    if(n==2) return 1;
    for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
void generate(position p) {
	int k;
	if(x==fx&&y==fy) {
		
		return;
	}
	for(k=0;k<4;k++) {
		p.x+=p.next[k][0];
		p.y+=p.next[k][1];
		if (graph[p.x][p.y]==0&&record[p.x][p.y]==0&&p.x>1&&p.x<=n&&p.y>0&&p.y<=m) {
			record[p.x][p.y]=1;
			generate(p);
			record[p.x][p.y]=0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int t=0;t<n;t++) cin>>x[t];
	generate(position p={.x=1,.y=1});
	
	/*for(int i=0;i<n;i++) {
		for(int j=0;j<n-1;j++) {
			for(int k=0;k<n-1;k++) {
				
			}
		}
	}*/
}
