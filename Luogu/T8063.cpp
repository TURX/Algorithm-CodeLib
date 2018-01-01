#include <iostream>
using namespace std;
int N,T,t_i,happy=0,nowhappy=0;
int main() {
	cin>>N>>T;
	for(int t=0;t<N;t++) {
		cin>>t_i;
		if(t_i<nowhappy) {
			nowhappy=t_i;
		} else {
			happy+=nowhappy;
			nowhappy=t_i;
		}
	}
	cout<<happy<<endl;
}
