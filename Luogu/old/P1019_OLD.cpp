#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int n,len; // Word Count, Total Length
string orig[21],recycle[21]; // Original String Array
string total,temp; // Just As What You See
char head; // The Dragon String's Head
using namespace std;
/*void dfs(string input) {
	len=max(len,input.length()); // Update the length if the string becomes longer
	for(int t=1;t<=n;t++) {
		if(recycle[t]>=2) continue; // It can't be recycled
		
	}
}*/
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int t=0;t<n;t++) {
		cin>>orig[t];
		//if(orig[t].length()>n) n=orig[t].length();
	}
	//cin>>head;
	int cat=0;
	for(int t1=0,temptr=0;t1<n;t1++) {
		for(int t2=0;t2<=orig[t1].length();t2++) {
			if(orig[t1][orig[t1].length()-t2]==orig[t1+1][t2-1]) {
				cat++;
				//orig[t1][orig[t1].length()-t2]='-';
				//orig[t1+1][t2-1]='\0';
			}
		}
	}
	cout<<cat<<endl;
	for(int t=0;t<n;t++) cout<<orig[t]<<endl;
	return 0;
}
