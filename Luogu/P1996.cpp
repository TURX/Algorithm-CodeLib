#include<iostream>
#include<memory.h>
using namespace std;
int n,m,t=0,index=0,temp = 0;
bool a[101];
int main() {
	memset(a,0,101);
	cin>>n>>m;
	memset(a,1,n);
	/*for(int t1=0;t3<n;t1++) {
		for(int t2=t1;t2<n;t2++) {
			if((t2-t1+1)%m!=0) continue;
			if(a[t2]!=0) {
				a[t2]=0;
				cout<<t2+1<<" ";
				t3++;
			}
		}
	}*/
	while (true) {
		if (t >= n)
			break;
		if (a[index%n])
			temp++;
		if (temp%m == 0) {
			cout << index % n + 1 << endl;
			a[index % n] = 0;
			temp = 0;
			t ++;
		}
		index = (index + 1) % n;
	}
} 
