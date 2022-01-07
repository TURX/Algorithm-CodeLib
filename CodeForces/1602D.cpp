#include <iostream>
using namespace std;

int n, a[300001], b[300001], dp[300001];

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[n - i]; // 地下i米可跳最大高度
	for (int i = 0; i < n; i++) cin >> b[n - i]; // 地下i米滑落的距离
	// dp[i] i次跳跃后，休息滑落之前所能到达的高度
	// 求dp[k]=n+b[k]中的k
	for (int i = 0; i < n; i++) {
		dp[i] = i - b[i]; // 不跳，直接滑，最差
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i] = max(dp[i], dp[i - b[i]] + a[i]); // 不跳或者从滑下去的点跳
			if (dp[i] == n + b[i]) { // 跳到了dp[k]=n+b[k]，输出解
				cout << i + 1 << endl;
				for (int k = 0; k <= i; k++) {
					cout << n - dp[k] << " ";
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl; // 无解
}
