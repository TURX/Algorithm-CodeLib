#include <cstdio>
using namespace std;

int main() {
	int ans = 0;
	char c;
	while ((c = getchar()) != EOF) {
		if (c == '1') ans++;
	}
	printf("%d\n", ans);
}
