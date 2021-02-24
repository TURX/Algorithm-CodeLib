#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1001;
int A[MAXN], F[MAXN], S;

int find(int x) {
    int ans = 0;
    for (int t = 1; t < x; t++) {
        if (x % t == 0) ans += t;
    }
    return ans;
}

int main() {
    cin >> S;
    for (int t = 1; t <= S; t++) A[t] = find(t);
    for (int i = 1; i <= S; i++) {
        for (int j = S; j >= i; j--) {
            F[j] = max(F[j - i]  + A[i], F[j]);
        }
    }
    cout << F[S] << endl;
}