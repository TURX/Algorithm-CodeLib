#include <cstdio>
using namespace std;

const int MAXN = 30;
int r[MAXN], c[MAXN], dl[MAXN], dr[MAXN], tot; // r: row, c: column, dl: left diagonal, dr: right diagonal, tot: total 

void print() {
	if (tot < 3) {
		for (int i = 1; i <= n; i++) printf("%d ", r[i]);
		printf("\n");
	}
	tot++;
}

void dfs(int q) { // q: queen
	if (q > n) {
		print();
		return;
	}
	for (int col = 1; col <= n; col++) {
		if (!dl[q - col + n - 1] && !dr[q + col] && !c[col]) { // is the position safe?
			r[q] = col;
			c[col] = 1;
			dr[q + col] = 1;
			dl[q - col + n - 1] = 1;
			dfs(q + 1);
			c[col] = 0;
			dr[q + col] = 0;
			dl[q - col + n - 1] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	dfs(0);
	printf("%d\n", tot);
	return 0;
}
