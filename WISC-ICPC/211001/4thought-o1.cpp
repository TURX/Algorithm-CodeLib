#include <iostream>
using namespace std;

int M, N;

struct Solution {
	bool valid = false;
	char op1, op2, op3;
} eval[2000003];

// 4(*/)4(*/)4(*/)4
// 4(*/)4(*/)4(+-)4
// 4(*/)4(+-)4(*/)4
// 4(*/)4(+-)4(+-)4
// 4(+-)4(+-)4(+-)4

int main() {
	freopen("test.in", "r", stdin);
	cin >> M;
	while (M--) {
		cin >> N;
		Solution& ans = eval[N + 1000000];
		if (ans.valid) {
			cout << "4 " << ans.op1 << " 4 " << ans.op2 << " 4 " << ans.op3 << " 4 = " << N << endl;
		} else {
			cout << "no solution" << endl;
		}
	}
}
