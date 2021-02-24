#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

const int MAXN = 10001;
int N, tmp, L = 0, A[MAXN];

int main() {
    cin >> N;
    for (int t = 0; t < N; t++) cin >> A[t];
    sort(A, A + N);
    for (int t = N - 1; t >= 0; t--) {
        if (A[t] >= L) L++;
        else break;
    }
    cout << L << endl;
    return 0;
}