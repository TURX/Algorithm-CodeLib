#include<stdio.h>
int main() {
	int arm, height[10];
	for(int t=0;t<10;t++) scanf("%d",&height[t]);
	scanf("%d",&arm);
	arm+=30;
	int result=0;
	for(int t=0;t<10;t++) if(height[t]<=arm) result++;
	printf("%d\n",result);
	return 0;
}
