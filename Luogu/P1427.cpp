#include<stdio.h>
int main() {
	int n[100];
	int t;
	for(t=0;t<100;t++) {
		int tn;
		scanf("%d",&tn);
		if(tn==0) break;
		n[t]=tn;
	}
	t--;
	for(;t>=0;t--) printf("%d ",n[t]);
	return 0;
}
