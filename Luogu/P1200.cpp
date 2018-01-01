#include<bits/stdc++.h>

int main(){
	char co_n[7],gr_n[7]; // Comet & Group
	unsigned int t_a=1;
	scanf("%s",&co_n);
	scanf("%s",&gr_n);
	for(int t=0;t<strlen(co_n);t++) t_a*=co_n[t]-64;
	int co_mod=t_a%47;t_a=1;
	for(int t=0;t<strlen(gr_n);t++) t_a*=gr_n[t]-64;
	if(co_mod==t_a%47) printf("GO\n"); else printf("STAY\n");
	return 0;
}
