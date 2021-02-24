#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 50001;

int N, M, inp, H[MAXN];

inline bool loc(const int x) {
    const int y = x % MAXN;
    int i = 0;
    while(i <= MAXN && H[(i + y) % MAXN] != x && H[(i + y) % MAXN]) i++;
    if(H[(i + y) % MAXN] == 0) {
        H[(i + y) % MAXN] = x;
        return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &N);
    while(N--) {
        memset(H, 0, sizeof(H));
        scanf("%d", &M);
        while(M--) {
            scanf("%d", &inp);
            if(!loc(inp)) printf("%d ", inp);
        }
        puts("");
    }
    return 0;
}