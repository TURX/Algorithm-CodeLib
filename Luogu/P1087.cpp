#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int N;
string S, ans;

struct Tree {
	char val;
	bool assigned = false;
} tree[100003];

void build(string S, int pos) {
	bool flagZero = false, flagOne = false;
	for(int t = 0; t < S.length(); t++) {
		if(S[t] == '0') flagZero = true;
		if(S[t] == '1') flagOne = true;
		if(flagZero && flagOne) {
			tree[pos].val = 'F';
			tree[pos].assigned = true;
			break;
		}
	}
	if(flagZero && !flagOne) {
		tree[pos].val = 'B';
		tree[pos].assigned = true;
	};
	if(flagOne && !flagZero) {
		tree[pos].val = 'I';
		tree[pos].assigned = true;
	};
	if(S.length() <= 1) return;
	build(S.substr(0, S.length() / 2), pos << 1);
	if(S.length() % 2) build(S.substr(S.length() / 2 + 1, S.length()), pos << 1 | 1); else build(S.substr(S.length() / 2, S.length()), pos << 1 | 1);
}

void search(int x) {
	ans.push_back(tree[x].val);
	if(tree[x << 1 | 1].assigned) search(x << 1 | 1);
	if(tree[x << 1].assigned) search(x << 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> S;
	build(S, 1);
	search(1);
	for(int t = ans.length() - 1; t >= 0; t--) {
		cout << ans[t];
	}
	cout << endl;
	return 0;
}
