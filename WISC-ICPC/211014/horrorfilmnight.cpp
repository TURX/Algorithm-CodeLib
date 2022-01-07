#include <iostream>
#include <map>
using namespace std;

bool ad = false, bd = false;
int a[1000001], b[1000001], na, nb, ans = 0;
map<int, int> M;

// 思路：消除A，B只有一个喜欢的重复项

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	cin >> na;
	for (int i = 0; i < na; i++) {
		cin >> a[i];
		M[a[i]] |= 1;
	}
	cin >> nb;
	for (int i = 0; i < nb; i++) {
		cin >> b[i];
		M[b[i]] |= 2;
	}
	for (pair<int, int> element : M) {
		if (element.second == 1) { // 01: only A like
			if (bd == true) continue;
			ad = false; bd = true;
		}
		else if (element.second == 2) { // 10: only B like
			if (ad == true) continue;
			ad = true; bd = false;
		}
		else if (element.second == 3) { // 11: both like
			ad = false; bd = false;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
