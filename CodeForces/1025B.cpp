#include <iostream>
#include <set>
#include <map>
using namespace std;

int N, Eptr;
unsigned long long A[150001][2], tmpGCD, lastGcd;//, Q[150001];

unsigned long long gcd(const unsigned long long& a, const unsigned long long& b) {
    return b ? gcd(b, a % b) : a;
}

/*
map<unsigned long long, int> Q;

struct W {
    unsigned long long GCD;
    int counter;
} E[150001];
*/
/*
struct QUtil {
    int qPtr;
    void add(const int& n) {
        if(t != n) Q[qPtr++] = n;
    }
    int query(const int& n) {
        for(int t = 0; t < qPtr; t++) {
            if(t == n) return t;
        }
        return -1;
    }
} QU;
*/

/*
inline void ins(unsigned long long GCD) {
    if(!Q[GCD]) {
            Q[GCD] = Eptr + 1; 
            E[Eptr++] = {GCD, 1};
            return;
    }
    E[Q[GCD]].counter++;
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 0; t < N; t++) {
        cin >> A[t][0] >> A[t][1];
    }
    lastGcd = A[0][0] * A[0][1];
    for(int t = 1; t < N; t++) {
        lastGcd = gcd(lastGcd, gcd(A[t - 1][0] * A[t - 1][1], A[t][0] * A[t][1]));
        // ins(gcd(A[t - 1][0] * A[t - 1][1], A[t][0] * A[t][1]));
        /*
        ins(gcd(A[t - 1][0], A[t][0])));
        ins(gcd(A[t - 1][0], A[t][1])));
        ins(gcd(A[t - 1][1], A[t][0])));
        ins(gcd(A[t - 1][1], A[t][1])));
        */
    }
    if(lastGcd == 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << lastGcd / 3 << endl;
    return 0;
}