#include<stdio.h>

int main() {
	int x;
	unsigned long long n,result=0;
	scanf("%d%lld",&x,&n);
	for(long t=0;t<n;t++){
		if(x!=6&&x!=7) result+=250;
		if(x==7) x=1; else x++;
	}
	printf("%lld\n",result);
	return 0;
}
