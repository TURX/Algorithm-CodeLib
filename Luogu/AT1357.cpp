#include <iostream>
using namespace std;

inline unsigned long long fastPower(unsigned long long b, unsigned long long p, unsigned long long k) {
	// This program can solve for b ^ p % k.
	int ans = 1;
	while(p > 0) {
		if(p % 2 != 0) {
			ans *= b % k;
		}
		b *= b % k;
		p >>= 1;
	}
	if(b == 1 && p == 0 && k == 1) return 0;
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    unsigned long long b, p, k;
    cin >> b >> p >> k;
    cout << fastPower(b, p, k) << endl;
    return 0;
}