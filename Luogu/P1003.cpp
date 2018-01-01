%:pragma GCC optimize(2)
#include <iostream>
using namespace std;
int n,ax,ay,bx,by,sx,sy,ans=-1;
int map[100000][4];
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int t=0;t<n;t++) cin>>map[t][0]>>map[t][1]>>map[t][2]>>map[t][3];
	cin>>sx>>sy;
	for(int t=0;t<n;t++) if(sx>=map[t][0]&&sx<=(map[t][0]+map[t][2])&&sy>=map[t][1]&&sy<=(map[t][1]+map[t][3])) ans=t+1;
	cout<<ans<<endl;
	return 0;
}
