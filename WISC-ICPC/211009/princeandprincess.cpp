#include <iostream>
#include <map>
using namespace std;

#define MAXN 250

int T, N, P, Q;
int prince[MAXN * 2 + 1], princess[MAXN * 2 + 1], pp[MAXN * 2 + 1];
map<int, int> prince_reverse;

int solve(int arr[], int size) {
	int ans = 0;
	int lis[2001];
	memset(lis, 0, sizeof(lis));
	for (int i = 1; i <= size; i++) {
		lis[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) lis[i] = max(lis[i], lis[j] + 1);
		}
		ans = max(ans, lis[i]);
	}
	return ans;
}

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		memset(prince, 0, sizeof(prince));
		memset(princess, 0, sizeof(princess));
		memset(pp, 0, sizeof(pp));
		prince_reverse.clear();

		// Input + Convert
		cin >> N >> P >> Q;
		for (int i = 1; i <= P; i++) {
			cin >> prince[i];
			prince_reverse[prince[i]] = i;
		}
		int ptr = 1;
		for (int i = 1; i <= Q; i++) {
			cin >> princess[i];
			if (prince_reverse[princess[i]]) pp[ptr++] = prince_reverse[princess[i]];
		}

		// LIS
		cout << "Case " << caseNum << ": " <<  solve(pp, ptr) << endl;
	}
}
