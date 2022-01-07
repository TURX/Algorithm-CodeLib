#include <iostream>
#include <algorithm>
using namespace std;

int t, n, k, a[101], ans = 0;

int main() {
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n - 2 * k; i++) ans += a[i];
		for (int i = k; i > 0; i--) {
			//cerr << "[]" << n - 2 * i << ", " << n - i << endl;
			if (a[n - k - i] == a[n - i]) ans++;
		}
		cout << ans << '\n';
	}
}
