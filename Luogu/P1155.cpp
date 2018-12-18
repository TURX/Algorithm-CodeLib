#include <iostream>
using namespace std;

int N, A[200003], dp[200003], sum = -0x7FFF;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 1; t <= N; t++) cin >> A[t];
    for(int i = 1; i <= N; i++) {
        dp[i] = max(A[i], dp[i - 1] + A[i]);
        sum = max(sum, dp[i]);
    }
    cout << sum << endl;
    return 0;
}