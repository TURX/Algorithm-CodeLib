%:pragma GCC optimize(2)
#include <iostream>
using namespace std;

int N;
unsigned long long A[150001][2], lastGcd;//, Q[150001];

unsigned long long gcd(const unsigned long long& a, const unsigned long long& b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 0; t < N; t++) {
        cin >> A[t][0] >> A[t][1];
    }
    lastGcd = A[0][0] * A[0][1];
    for(int t = 0; t < N; t++) {
        lastGcd = gcd(lastGcd, A[t][0] * A[t][1] / gcd(A[t][0], A[t][1]));
    }
    if(lastGcd == 1) {
        cout << -1 << endl;
        return 0;
    }
    for(unsigned long long i = 2; i <= 50000; i++) {
        if(lastGcd % i == 0) {
            cout << i << endl;
            return 0;
        }
    } 
    if(gcd(lastGcd, A[0][0]) != 1) cout << gcd(lastGcd, A[0][0]) << endl;
    else cout << gcd(lastGcd, A[0][1]) << endl;
    return 0;
}