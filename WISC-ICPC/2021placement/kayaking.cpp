#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 300001
int m, c[MAXN], num[5], strength[5], temp[5];

struct boat {
    int a, b, val;
} g[15];

bool solve(int mid) {
	int cnt = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = i; j <= 3; j++) {
			cnt++;
			g[cnt].a = i, g[cnt].b = j;
			g[cnt].val = strength[i] + strength[j];
		}
	}
	for (int i = 1; i <= 3; i++)
		temp[i] = num[i];
	for (int i = 1; i <= m; i++) {
		int flag = 0;
		for (int j = 1; j <= cnt; j++) {
			if (temp[g[j].a] == 0 || temp[g[j].b] == 0 || g[j].val * c[i] < mid) // no person OR invalid solution
				continue;
			if (g[j].a == g[j].b && temp[g[j].a] < 2) // same person
				continue;
			temp[g[j].a]--, temp[g[j].b]--;
			flag = 1;
			break;
		}
		if (flag == 0)
			return false;
	}
	return true;
}

int main() {
	for (int i = 1; i <= 3; i++) cin >> num[i];
	for (int i = 1; i <= 3; i++) cin >> strength[i];
	m = (num[1] + num[2] + num[3]) / 2;
	for (int i = 1; i <= m; i++)
		cin >> c[i];
	sort(c + 1, c + m + 1);
	int l = 0, r = 1000000000, ans = 0;
	while (r >= l) {
		int mid = (l + r) / 2;
		if (solve(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
