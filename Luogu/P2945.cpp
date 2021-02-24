#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 25000;
int N, X, Y;
long long M[MAXN], B[MAXN], tot = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> X >> Y;
    for (int t = 0; t < N; t++) {
        cin >> M[t] >> B[t];
    }
    sort(M, M + N);
    sort(B, B + N);
    for (int t = 0; t < N; t++) {
        if (M[t] == B[t]) continue;
        if (M[t] < B[t]) tot += X * (B[t] - M[t]);
        else tot += Y * (M[t] - B[t]);
    }
    cout << tot << endl;
    return 0;
}