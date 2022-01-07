#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 300000

struct Researcher {
	int a, s;
	friend bool operator<(Researcher lhs, Researcher rhs) {
		return lhs.a < rhs.a;
	}
} R[MAXN];

int N, M, ans = 0;
priority_queue<int, vector<int>, greater<int> > Q; // increasing

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> R[i].a >> R[i].s;
	}
	sort(R, R + N);
	for (int i = 0; i < N; i++) {
		while (!Q.empty() && Q.top() + M < R[i].a)
			Q.pop(); // expired
		if (Q.empty() || (!Q.empty() && Q.top() > R[i].a)) {
			// no workstation is available or not leaved yet
			ans++;
		} else {
			Q.pop();
		}
		/*
		if (!Q.empty() && Q.top() <= R[i].a) // workstation available
			Q.pop();
		else
			ans++;
		*/
		Q.push(R[i].a + R[i].s);
	}
	cout << N - ans << endl;
	return 0;
}
