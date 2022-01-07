#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n, cars[2001];

int solve() {
	int ans = 0;
	int lis[2001], lds[2001];
	memset(lis, 0, sizeof(lis));
	memset(lds, 0, sizeof(lds));
	for (int i = 1; i <= n; i++) {
		lis[i] = lds[i] = 1;
		for (int j = 1; j < i; j++) {
			if (cars[j] < cars[i]) lis[i] = max(lis[i], lis[j] + 1);
			if (cars[j] > cars[i]) lds[i] = max(lds[i], lds[j] + 1);
		}
		ans = max(ans, lis[i] + lds[i] - 1);
	}
	return ans;
}

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	cin >> n;
	// 逆序求解：要得到以i开始的最长子序列，而不是传统以i结尾的
	for (int i = n; i >= 1; i--) cin >> cars[i];
	cout << solve() << endl;
	return 0;
}
