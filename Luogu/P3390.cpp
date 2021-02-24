#include <iostream>
using namespace std;

int fastPower(int b, int p) {
    int ans = 1;
    while(p > 0) {
        if(p % 2 != 0) {
            ans *= b;
        }
        b *= b;
        p >>= 1;
    }
    if(b == 1 && p == 0 && k == 1) return 0;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
}