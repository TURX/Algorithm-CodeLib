#include <stdio.h>
#include <string.h>
#include <math.h>

int T, A, B;
char S[5], O, N[20];

void ans(char O, int A, int B) {
    switch (O) {
        case 'a':
            sprintf(N, "%d+%d=%d", A, B, A + B);
            break;
        case 'b':
            sprintf(N, "%d-%d=%d", A, B, A - B);
            break;
        case 'c':
            sprintf(N, "%d*%d=%d", A, B, A * B);
            break;
    }
}

int stoi(char* s) {
    int a = 0, l = strlen(s);
    for (int i = 0; i < l; i++)
        a += (s[l - i - 1] - '0') * pow(10, i);
    return a;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s %d", S, &A);
        if (S[0] == 'a' || S[0] == 'b' || S[0] == 'c') {
            scanf("%d", &B);
            O = S[0];
        } else {
            B = A;
            A = stoi(S);
        }
        ans(O, A, B);
        printf("%s\n%zu\n", N, strlen(N));
    }
}
