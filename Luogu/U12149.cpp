#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
long long r;
int a,b,c,n,m1,m2;
int search(int target[50], int keyword) {
	int arr[50];
	memset(arr,0,50);
	arr=target;
	for(int t=0;t<50;t++) if(arr[t]==keyword) return t;
	return -1;
}
int main() {
	scanf("%d%d%d%lld",&n,&m1,&m2,&r);
	int am1[m1][2],am2[m2][3];
	bool teleported[n];
	bool unteleported[n];
	memset(teleported,0,n);
	memset(unteleported,1,n);
	for(int t=0;t<m1;t++) scanf("%d%d",&am1[t][0],&am1[t][1]);
	for(int t=0;t<m2;t++) scanf("%d%d%d",&am2[t][0],&am2[t][1],&am2[t][2]);
	for(int t1=0;t1<n;t1++) {
		for(int t2=0,flag=0;t2<r;t2++) {
			for(int t3=0;t3<m1;t3++) {
				if(search(am1[t3],t1)==-1) continue; else {
					
					flag=1;
					break;
				}
			}
			if(flag==0) {
				for(int t3=0;t3<m2;t3++) {
					if(search(am2[t3],t1)==-1) continue; else {
						flag=1;
						break;
					}
				}
			}
			if(flag==1) {
				
			}
		}
	}
}
