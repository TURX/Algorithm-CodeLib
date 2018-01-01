#include <iostream>
#include <memory.h>
using namespace std;
// Dijkstra http://www.cnblogs.com/biyeymyhjob/archive/2012/07/31/2615833.html
int n,m,s,map[10000][10000];
inline void ins(int fi,int gi,int wi) { // Insertion
	int posx=0,posy=0;
	bool flag=false;
	for(;posy<10000;posy++) {
		for(;posx<10000;posx++) {
			if(!map[posx][posy]) {
				flag=true;
				break;
			}
		}
		if(flag==true) {
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	memset(map,0,sizeof(map));
	cin>>n>>m>>s;
	for(int t=0;t<m;t++) {
		int fi,gi,wi;
		cin>>fi>>gi>>wi;
		ins(fi,gi,wi);
	}
}
