#include <cstdio>
using namespace std;

const int MAXN = 27;
int r[MAXN], c[MAXN], sl[MAXN], sr[MAXN], n, tot; // row, column, slope from left up corner to right down corner, slope from right up corner to left down corner

/*

Explaination of sl, sr

the sum of i and j is constant and unique for each right diagonal (i: row, j: column)
the difference of i and j is constant and unique for each left diagonal (i: row, j: column)


from geeksforgeeks

*/

void print() {
	if (tot < 3) {
		for (int i = 1; i <= n; i++) printf("%d ", r[i]);
		printf("\n");
	}
	tot++;
}

void dfs(int i) {
	if (i > n) {
		print();
		return;
	}
	for (int j = 1; j <= n; j++) {
		if ((!c[j]) && (!sr[i + j]) && (!sl[i - j + n])) { // sl: would be negative if only i - j is applied
			r[i] = j;
			c[j] = true;
			sl[i - j + n] = true;
			sr[i + j] = true;
			dfs(i + 1);
			c[j] = false;
			sl[i - j + n] = false;
			sr[i + j] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	dfs(1);
	printf("%d\n", tot);
	return 0;
}
