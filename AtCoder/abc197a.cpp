#include <cstdio>
using namespace std;

int main() {
	char cf, c;
	scanf("%c", &cf);
	while (c = getchar()) {
		if (c == EOF || c == '\n') break;
		putchar(c);
	}
	putchar(cf);
}
