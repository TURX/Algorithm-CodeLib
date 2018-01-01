#include<bits/stdc++.h>

int main() {
	int a[16],b[8],nowday=0;
	for(int count=0;count<=13;count++) scanf("%d",&a[count]);
	for(int count=0,tempnum=0;count<=6;count++,tempnum=tempnum+2) b[count]=a[tempnum]+a[tempnum+1];
	for(int count=0,tempnum=0;count<=6;count++) {
		if (b[count]>tempnum) {
			tempnum=b[count];
			nowday=count+1;
		}
	}
	printf("%d",nowday);
	return 0;
}
