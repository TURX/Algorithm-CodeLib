#include <iostream>
using namespace std;

struct App {
	int d, s;
	friend bool operator<(App lhs, App rhs) {
		return lhs.d - lhs.s > rhs.d - rhs.s;
	}
} phone[10001];

int N, C, dp[10001];

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> phone[i].d >> phone[i].s;
	}
	sort(phone + 1, phone + N + 1);
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = C; j >= phone[i].s; j--) {
			dp[j] = max(dp[j], dp[j - phone[i].s] + 1);
		}
	}
	int ans = 0;
	for (int j = 0; j <= C; j++) {
		ans = max(ans, dp[j]);
		cout << dp[j] << " ";
	}
	cout << endl << ans << endl;
	return 0;
}
