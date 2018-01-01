#include<stdio.h>
int main() {
	double distance=2;
	double x;
	int step=0;
	scanf("%lf",&x);
	while(x>=0) {
		x-=distance;
		distance*=0.98;
		step++;
	}
	printf("%d",step);
	return 0;
} 
