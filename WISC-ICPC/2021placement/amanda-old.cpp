#include <iostream>
#include <vector>
using namespace std;

#define MAXN 200001

int N, M, a, b, c, cnt = 0;
struct Airport {
	bool built = false;
} airports[MAXN];
struct Operation {
	int a, b, c;
	Operation(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	friend bool operator<(Operation lhs, Operation rhs) {
		return lhs.c > rhs.c;
	}
};
vector<Operation> ops;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		ops.push_back(Operation(a, b, c));
	}
	sort(ops.begin(), ops.end());
	for (int i = 0; i < M; i++) {
		a = ops[i].a; b = ops[i].b; c = ops[i].c;
		switch (c) {
		case 0:
			if (airports[a].built || airports[b].built) {
				cout << "impossible" << endl;
				return 0;
			}
			break;
		case 1:
			if (airports[a].built && airports[b].built) {
				cout << "impossible" << endl;
				return 0;
			}
			if (airports[a].built || airports[b].built) continue;
			if (!airports[a].built) airports[a].built = true;
			else airports[b].built = true;
			cnt++;
			break;
		case 2:
			if (airports[a].built || airports[b].built) cnt--;
			if (airports[a].built && airports[b].built) cnt--;
			airports[a].built = true;
			airports[b].built = true;
			cnt += 2;
			break;
		}
	}
	cout << cnt << endl;
}
