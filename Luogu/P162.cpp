// P1162
#include <iostream>
#include <queue>
using namespace std;
struct point {
	int x,y;
};
queue<point> q;
point make_point(int x,int y) {
	point temp;
	temp.x=x; temp.y=y;
	return temp;
}
const int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int map[100][100],n;
void outputMap() {
	clog<<"[LOG] Map:"<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			clog<<map[i][j]<<" ";
		}
		clog<<endl;
	}
	for(int t=0;t<n;t++) {
		clog<<"--";
	}
	clog<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>map[i][j];
		}
	}
	outputMap();
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			
		}
	}
}
