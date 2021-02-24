#include <cstdio>
#define N 3000010
using namespace std;

int inv[N], n, p;

int main() {
    scanf("%d%d", &n, &p);
    inv[1] = 1;
    printf("1\n");
    for (int i = 2; i <= n; i++) {
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
        printf("%d\n", inv[i]);
    }
}