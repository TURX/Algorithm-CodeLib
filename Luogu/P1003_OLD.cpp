#include <stdio.h>
#include <memory.h>
#include <string.h>
struct carpet_storage
{
	unsigned int a;
	unsigned int b;
	unsigned int g;
	unsigned int k;
}carpet[10000];
unsigned int carpet_result[200][200];
int main() {
	memset(&carpet_result,0,sizeof(carpet_result));
	memset(&carpet,0,sizeof(carpet));
	int n; // count
	scanf("%d", &n);
	for (int t = 0; t < n; t++) scanf("%d%d%d%d", &carpet->a, &carpet->b, &carpet->g, &carpet->k);
	int tx, ty; // target
	scanf("%d%d", &tx, &ty);
}