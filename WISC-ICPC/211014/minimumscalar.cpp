#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int l, int r) {
	return l > r;
}

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	int cases;
	cin >> cases;
	for (int c = 1; c <= cases; c++) {
		long long ans = 0;
		int n;
		cin >> n;
		int x[n], y[n];
		for (int i = 0; i < n; i++) cin >> x[i];
		for (int i = 0; i < n; i++) cin >> y[i];
		sort(x, x + n);
		sort(y, y + n, cmp);
		for (int i = 0; i < n; i++) {
			ans += ((long long)x[i] * (long long)y[i]);
		}
		cout << "Case #" << c << ": " << ans << endl;
	}
	return 0;
}
