#include <iostream>
using namespace std;

#define MAXN 40003

int t, n;
long long a[MAXN], b[MAXN], sumcoef, sumb, ss, pre;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		sumcoef = n * (n + 1) / 2;
		sumb = 0;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			sumb += b[i];
		}
		if (sumb % sumcoef != 0) {
			cout << "NO" << endl;
			continue;
		}
		ss = sumb / sumcoef;
		bool breakflag = false;
		for (int i = 0; i < n; i++) {
			pre = i - 1;
			if (pre == -1) pre = n - 1;
			if ((ss - b[i] + b[pre]) % n != 0) {
				cout << "NO" << endl;
				breakflag = true;
				break;
			}
			a[i] = (ss - b[i] + b[pre]) / n;
			if (a[i] <= 0) {
				cout << "NO" << endl;
				breakflag = true;
				break;
			}
		}
		if (breakflag) continue;
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
