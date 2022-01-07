#include <iostream>
#include <vector>
using namespace std;

#define MAXJ 1000000000

int l, n, m;
vector<int> dist;

int jump(int now, int min_jump) {
	int next = now + 1;
	if (next >= dist.size()) return dist.size();
	while (dist[next] - dist[now] < min_jump) {
		next++;
		if (next >= dist.size()) return dist.size();
	}
	return next;
}

bool check(int min_jump) {
	int cnt = 0, now = 0, next = 0;
	while (now < dist.size()) {
		next = jump(now, min_jump);
		cnt += next - now - 1;
		// if (debug) cerr << "cnt: " << cnt << " now: " << now << " next: " << next << endl;
		now = next;
	}
	return cnt <= m;
}

/*
bool check(int min_jump) {
	return check(min_jump, false);
}
*/

int solve(int low, int high) {
	//bool debug = false;
	//if (low == 0 && high == 14) debug = true;
	if (low == high) return low;
	if (check(high)) return high;
	int mid = (low + high) / 2;
	if (mid != low && check(mid)) return solve(mid, high);
	if (check(low)) return solve(low, mid);
	return -1;
}

int main() {
	cin >> l >> n >> m;
	dist.push_back(0);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		dist.push_back(t);
	}
	dist.push_back(l);
	cout << solve(0, MAXJ) << endl;
}
