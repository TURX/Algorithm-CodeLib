#include <iostream>
using namespace std;

const int MAX_N = 32000, MAX_M = 60;

struct Item {
    int v, p, q;
} I[MAX_M];

int DP[MAX_N], ANS[MAX_N];

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> I[i].v >> I[i].p >> I[i].q;
        I[i].p *= I[i].v;
    }
    for (int i = 1; i <= M; i++) {
        if (!I[i].q) { // Main
            for (int j = 0; j < I[i].v; j++) DP[j] = 0;
            for (int j = I[i].v; j <= N; j++) DP[j] = ANS[j - I[i].v] + I[i].p;
            for (int j = 1; j <= M; j++)
                if (I[j].q == i)
                    for (int k = N; k >= I[i].v + I[j].v; k--)
                        DP[k] = max(DP[k], DP[k - I[j].v] + I[j].p);
            for (int j = I[i].v; j <= N; j++) ANS[j] = max(ANS[j], DP[j]);
        }
    }
    cout << ANS[N] << endl;
    return 0;
}