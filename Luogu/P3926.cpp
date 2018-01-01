#include <iostream>
using namespace std;
long long a,c,p,q,r,x,t=0;
bool stat=0;
int main() {
	ios::sync_with_stdio(false);
	cin>>a>>c>>p>>q>>r>>x;
	while(true) {
		if(a<c) {
			if(t>x-p) break;
			t+=p;
			a++;
		}
		if(a>=c) {
			if(t+q>x-r) break;
			t+=r;
			a++;
		}
	}
	cout<<a<<endl;
	return 0;
}
