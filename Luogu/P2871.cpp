#include <iostream>
using namespace std;

const int MAXN = 3403;
const int MAXM = 12880;
int N, M, C[MAXN], W[MAXN], F[MAXM];

int main() {
    cin >> N >> M;
    for (int t = 1; t <= N; t++) cin >> C[t] >> W[t];
    for (int i = 1; i <= N; i++) {
        for (int v = M; v >= C[i]; v--) {
            F[v] = max(F[v], F[v - C[i]] + W[i]);
        }
    }
    cout << F[M] << endl;
}