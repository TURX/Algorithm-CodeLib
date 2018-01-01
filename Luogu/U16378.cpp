#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
struct trans {
	float x,y;
	float z() {
		return x/y;
	}
};
int m,n;
float maxScore=0;
vector<trans> p;
/*
vector<vector<int> > p;
vector<int> make_row(int x,int y) {
	vector<int> trans;
	trans.push_back(x);
	trans.push_back(y);
	return trans;
}
*/
trans gen(int x,int y) {
	trans temp;
	temp.x=x; temp.y=y;
	return temp;
}
int main() {
	cin>>m>>n;
	for(int t=0,i1,i2;t<2*n;t++) {
		while(getchar()!='\n');
		scanf("%d/%d",&i1,&i2);
		// p.push_back(make_row(i1,i2));
		p.push_back(gen(i1,i2));
	}
	int point_first=0;
	for(int t=0;t<2*n;t++) {
		if(p.size()-point_first<0) break;
		int totalGet=0,totalTot=0;
		float total=0;
		for(int u=point_first;u<m;u++) {
			/*totalGet+=p.at(u)[0];
			totalTot+=p.at(u)[1];*/
			total+=p.at(u).z();
		}
		maxScore=max(maxScore,total);
		// maxScore=max(maxScore,((float)totalGet/(float)totalTot));
		point_first++;
	}
	printf("%.1f%%",maxScore*100);
	return 0;
}
