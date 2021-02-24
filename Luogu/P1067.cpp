#include <cstdio>
#include <vector>
using namespace std;

int N, D[101];
bool plusFlag = false;

int main() {
    scanf("%d", &N);
    for (int t = N; t >= 0; t--) {
        scanf("%d", &D[t]);
    }
    for (int t = N; t >= 0; t--) {
        if (D[t]) {
            if (plusFlag && D[t] > 0) printf("+");
            plusFlag = true;
            if ((D[t] != 1 && D[t] != -1) || t == 0) printf("%d", D[t]);
            else {
                if (D[t] == -1) printf("-");
            }
            if (t >= 1) printf("x");
            if (t >= 2) printf("^%d", t);
        }
    }
    printf("\n");
    return 0;
}