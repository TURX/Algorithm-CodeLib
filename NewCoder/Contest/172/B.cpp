#include <iostream>
using namespace std;

unsigned long long L, R, L1, R1;

unsigned long long get(unsigned long long s) {
    unsigned long long ans = 1;
    while(s) {
        ans *= (s % 10);
        s /= 10;
    }
    return ans;
}

unsigned long long calc() {
    unsigned long long ans = 0;
    if(L == R || L1 == R1) return 0;
    for(unsigned long long left = L; left < R; left++) {
        unsigned long long tmp = get(left);
        if(tmp >= L1 && tmp <= R1) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> L >> R >> L1 >> R1;
    cout << calc() << endl;
    return 0;
}