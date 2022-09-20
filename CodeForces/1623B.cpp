#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Interval {
	Interval(int l, int r) {
		this->l = l;
		this->r = r;
		this->diff = r - l;
	}
	int l, r, diff;
};

bool cmpi(Interval l, Interval r) {
	if (l.diff == r.diff) {
		if (l.l == r.l) {
			return l.r < r.r;
		}
		return l.l < r.l;
	}
	return l.diff < r.diff;
}

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		vector<Interval> V;
		unordered_map<int, int> M;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			V.push_back(Interval(x, y));
		}
		sort(V.begin(), V.end(), cmpi);
		for (vector<Interval>::iterator it = V.begin(); it != V.end(); ++it) {
			int ans;
			if (M[it->l]) {
				ans = M[it->l] + 1;
				M[it->l] = max(M[it->l], it->r);
			} else {
				ans = it->l;
				M[it->l] = it->r;
			}
			cout << it->l << ' ' << it->r << ' ' << ans << endl;
		}
		cout << endl;
	}
	return 0;
}
