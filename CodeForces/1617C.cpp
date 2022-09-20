#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

set<int> P;
vector<int> W;
int T, N, tmp, ans;

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N;
		P.clear();
		W.clear();
		for (int i = 1; i <= N; i++) P.insert(i);
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			if (tmp <= N) {
				if (!P.count(tmp)) W.push_back(tmp);
				else P.erase(tmp);
			}
			else W.push_back(tmp);
		}
		sort(W.begin(), W.end());
		// now we have a set P of numbers that the permutation set currently lacks
		// and a set W of exceeded numbers that should not be in the permutation set
		for (vector<int>::iterator it = W.begin(); it != W.end(); it++) {
			if (*P.begin() >= ceil(*it / 2.0)) {
				ans = -1;
				break;
			}
			P.erase(P.begin());
			ans++;
		}
		cout << ans << endl;
	}
}
