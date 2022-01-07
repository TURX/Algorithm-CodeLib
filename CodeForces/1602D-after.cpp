#include <iostream>
using namespace std;

int n, a[300001], b[300001], dp[300001];

// i当前位置 i-a[i]跳上去的位置 i-a[i]+b[i-a[i]]跳上去又滑下来

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i - a[i]; j <= i; j++) { // i-a[i]跳上去但不下滑
			dp[i] = min(dp[i], dp[j] + b[j]);
		}
		dp[i]++;
	}
	cout << dp[n] << endl;
}
