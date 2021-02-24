#include <iostream>
using namespace std;

const int M_N = 500, M_H = 45000;

int H, N, S[M_N + 1], DP[M_H + 1];

int main () {
    cin >> H >> N;
    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= N; i++)
        for (int j = H; j >= S[i]; j--)
            DP[j] = max(DP[j], DP[j - S[i]] + S[i]);
    int ans = 0;
    for (int i = 0; i <= H; i++) ans = max(ans, DP[i]);
    cout << ans << endl;
    return 0;
}