#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii; typedef vector<int> vi;

// KMP from kactl

vi pi(const string &s) {
	vi p(sz(s));
	rep(i, 1, sz(s)) {
		int g = p[i - 1];
		while (g && s[i] != s[g])
			g = p[g - 1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string &s, const string &pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i, sz(p) - sz(s), sz(p)) if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}

int main() {
	set<int> pos;
	set<char> Aset, Bset;
	string A, B;
	cin >> A >> B;
	for (int i = 0; i < A.length(); i++)
		Aset.insert(A[i]);
	for (int i = 0; i < B.length(); i++)
		Bset.insert(B[i]);
	if (Aset.size() < Bset.size()) {
		cout << 0 << endl;
		return 0;
	} // Aset >= Bset
	// use distinct chars of Aset to replace those in Bset
	vector<char> Avec(all(Aset));
	vector<char> Bvec(all(Bset));
	while (next_permutation(Avec.begin(), Avec.end())) {
		unordered_map<char, char> castMap;
		for (int i = 0; i < Bvec.size(); i++)
			castMap[Bvec[i]] = Avec[i];
		string tmpB;
		for (int i = 0; i < B.length(); i++)
			tmpB.push_back(castMap[B[i]]);
		vi tmpPos = match(A, tmpB);
		for (int i = 0; i < tmpPos.size(); i++)
			pos.insert(tmpPos[i]);
	}
	if (pos.size() == 1) {
		int position = *pos.begin();
		for (int i = position; i < position + B.length(); i++)
			cout << A[i];
		cout << endl;
	} else {
		cout << pos.size() << endl;
	}
	return 0;
}
