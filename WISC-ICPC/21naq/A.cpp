#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	string N;
	cin >> N;
	set<int> S;
	for (int i = 0; i <= 9; i++) {
		S.insert(i);
	}
	for (int i = 0; i < N.length(); i++) {
		if (S.count(N[i] - '0')) S.erase(N[i] - '0');
	}
	if (S.size() == 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	string lower, upper, longer;
	vector<int> V;
	for (auto it = S.begin(); it != S.end(); ++it) {
		V.push_back(*it);
	}
	if (V[0] == 0) {
		if (V.size() > 1) longer.push_back(V[1] + '0');
	}
	else longer.push_back(V[0] + '0');
	for (int i = 0; i < N.length(); i++) {
		if (i == 0) {
			int c = N[i] - '0';
			bool pushed = false;
			for (int j = 0; j < V.size() - 1; j++) {
				if (c - V[j] > 0 && V[j + 1] - c > 0) {
					lower.push_back(V[j] + '0');
					upper.push_back(V[j + 1] + '0');
					longer.push_back(V[j + 1] + '0');
					pushed = true;
					break;
				}
			}
			if (!pushed) {
				lower.push_back(V[V.size() - 1] + '0');
				upper.push_back(V[0] + '0');
			}
		} else {
			lower.push_back(V[V.size() - 1] + '0');
			upper.push_back(V[0] + '0');
		}
		longer.push_back(V[0] + '0');
	}
	long long li = stoll(lower), ui = stoll(upper), ni = stoll(N), loi = stoll(longer);
	long long opt;
	if (abs(ni - li) == abs(ui - ni)) {
		cout << li << " " << ui << endl;
		return 0;
	}
	else if (abs(ni - li) < abs(ui - ni)) opt = li;
	else opt = ui;
	if (abs(loi - ni) < abs(opt - ni)) cout << loi << endl;
	else cout << opt << endl;
}
