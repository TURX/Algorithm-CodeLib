#include <cstdio>
using namespace std;

int main() {
	char c;
	while ((c = getchar()) != EOF) {
		if (c == '.') return 0;
		putchar(c);
	}
}
