#include <cstdio>
using namespace std;

long long a, b, n;

int main() {
	scanf("%lld%lld%lld", &a, &b, &n);
	printf("%lld\n", (a + a + (b - a) * (n - 1)) * n / 2);
}
