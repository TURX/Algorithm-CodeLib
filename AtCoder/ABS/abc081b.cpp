#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n, g, t, ans = 0;
	cin >> n >> g;
	for (int i = 1; i < n; i++) {
		cin >> t;
		g = gcd(g, t);
	}
	while (g % 2 == 0) {
		g /= 2;
		ans++;
	}
	cout << ans << endl;
}
