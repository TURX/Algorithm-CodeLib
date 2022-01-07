#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> Q;
map<int, vector<int>> M;
int N, T;
unsigned long long ans = 0;

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int amount, time;
		cin >> amount >> time;
		M[time].push_back(amount);
	}
	for (int i = T; i >= 0; i--) {
		for (int j = 0; j < M[i].size(); j++) {
			Q.push(M[i][j]);
		}
		if (!Q.empty()) {
			ans += Q.top();
			Q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}
