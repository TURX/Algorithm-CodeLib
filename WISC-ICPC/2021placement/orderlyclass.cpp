#include <iostream>
#include <string>
using namespace std;

string A, B;

string reverse(string s) {
	string out = "";
	for (int i = s.length() - 1; i >= 0; i--) out.push_back(s[i]);
	return out;
}

int solve(int l, int r) {
	if (l < 0 || r > A.length()) return 0;
	if (reverse(A.substr(l, r - l + 1)) == B.substr(l, r - l + 1)) return 1;
	return 0;
}

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin >> A >> B;
	int left = 0, right = A.length();
	for (int i = 0; i < A.length(); i++) {
		if (A[i] != B[i]) {
			left = i;
			break;
		}
	}
	for (int i = A.length(); i >= left; i--) {
		if (A[i] != B[i]) {
			right = i;
			break;
		}
	}
	int ans = solve(left, right);
	if (ans == 1) {
		int i = left - 1, j = right + 1;
		while (i >= 0 && j < A.length() && A[i] == A[j]) {
			i--;
			j++;
			ans++;
		}
	}
	cout << ans << endl;
}
