#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

int main() {
	unsigned long long target=1;
	int t;
	int ans;
	long long k;
	scanf("%d%lld",&t,&k);
	if(t==0) {
		long long t2=1;
		for(int te=0;te<k;te++) {
			t2*=10;
		}
	}
	for(int te=0;te<k-1;te++) {
		char buffer[21];
		sprintf(buffer,"%ulld",target);
		ans++;
		target*=2;
	}
	printf("%d\n",ans);
}
