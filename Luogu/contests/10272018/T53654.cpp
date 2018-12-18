#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 200003

bool T[MAXN];
int N, K;
long long A[MAXN], maxNumber = -0x7FFFFFFFFFFFFFFF, total;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int t = 0; t < N; t++) cin >> A[t];
    for(int t = 0; t < N; t++) cin >> T[t];
    for(int t = 0; t < K; t++) total += A[t];
    for(int t = K; t < N; t++) total += A[t] * T[t];
    for(int t = 1; t < N - K + 1; t++) {
        if(!T[t - 1]) total -= A[t - 1];
        if(!T[t + K - 1]) total += A[t + K - 1];
        maxNumber = max(maxNumber, total);
    }
    cout << maxNumber << endl;
    return 0;
}