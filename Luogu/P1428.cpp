#include<stdio.h>
int main(){
	int n;
	int cute[100];
	scanf("%d",&n);
	for(int t=0;t<n;t++) scanf("%d",&cute[t]);
	for(int t=0;t<n;t++){
		int st=0;
		for(int t2=0;t2<t;t2++) {
			if(cute[t]>cute[t2]) st++;
		}
		printf("%d ",st);
	}
	printf("\n");
	return 0;
}
