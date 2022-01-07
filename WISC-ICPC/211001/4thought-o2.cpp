#include <iostream>
#include <cstring>
#include <stack>
#include <map>
using namespace std;

struct Solution {
	bool mode = 0;
	char op[3];
	Solution(bool mode, char op[]) {
		this->mode = mode;
		memcpy(this->op, op, strlen(this->op));
	}
};

map<int, Solution> ms;

int calc(char op, int n, int m) {
	if (op == '+') return n + m;
	else if (op == '-') return n - m;
	else if (op == '*') return n * m;
	else if (op == '/') return n / m;
	return INT32_MIN;
}

// 1: 前缀表达式求值ABC4444，加减在乘除前面，如++*，即(((4 A 4) B 4) C 4)
int eval1(char op[]) {
	bool high_priority = false;
	for (int i = 0; i < 3; i++) {
		if (op[i] == '+' || op[i] == '-') {
			if (high_priority) return INT32_MIN; // invalid
		} else if (op[i] == '*' || op[i] == '/') {
			high_priority = true;
		}
	}
	stack<int> tmp;
	for (int i = 0; i < 4; i++) tmp.push(4);
	for (int i = 2; i >= 0; i--) {
		int n = tmp.top(); tmp.pop();
		int m = tmp.top(); tmp.pop();
		tmp.push(calc(op[i], n, m));
	}
	return tmp.top();
}

// 2: 前缀表达式求值ABC4444，A为+-，即(4 ? 4) +/- (4 ? 4)，其他已被1涵盖
int eval2(char op[]) {
	if (op[0] != '+' && op[0] != '-') return INT32_MIN; // invalid
	int n, m;
	m = calc(op[2], 4, 4);
	n = calc(op[1], 4, 4);
	return calc(op[0], n, m);
}

void record(char op[], int ans, bool mode) {
	if (ans != INT32_MIN && ms.count(ans) == 0) {
		ms[ans] = Solution(mode, op);
	}
}

void solve(char op[], int layer) {
	if (layer == 3) {
		int ans;
		ans = eval1(op);
		record(op, ans, 0);
		ans = eval2(op);
		record(op, ans, 1);
		return;
	}
	op[layer] = '+';
	solve(op, layer + 1);
	op[layer] = '-';
	solve(op, layer + 1);
	op[layer] = '*';
	solve(op, layer + 1);
	op[layer] = '/';
	solve(op, layer + 1);
}

int main() {
	freopen("test.in", "r", stdin);
	char op_tmp[3];
	solve(op_tmp, 0);
	int M;
	cin >> M;
	while (M--) {
		int N;
		cin >> N;
		if (ms.count(N)) {
			// cout << ans.op << endl;
			if (ms[N].mode) {
				cout << "4 " << ms[N].op[1] << " 4 " << ms[N].op[0] << " 4 " << ms[N].op[2] << " 4 = " << N << endl; // (4 ? 4) ? (4 ? 4)
			} else {
				cout << "4 " << ms[N].op[2] << " 4 " << ms[N].op[1] << " 4 " << ms[N].op[0] << " 4 = " << N << endl; // ((4 ? 4) ? 4) ? 4
			}
		} else {
			cout << "no solution" << endl;
		}
	}
}
