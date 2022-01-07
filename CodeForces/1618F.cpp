#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removeLeadingZeroes(string str, bool inverse) {
	// 0: leading, 1: ending
	string result;
	bool endLeadingZeroes = false;
	if (!inverse)
		for (string::iterator it = str.begin(); it != str.end(); ++it) {
			if (endLeadingZeroes) result += *it;
			else if (*it != '0') {
				endLeadingZeroes = true;
				result += *it;
			}
		}
	else {
		for (int i = str.length() - 1; i >= 0; i--) {
			if (endLeadingZeroes) result += str[i];
			else if (str[i] != '0') {
				endLeadingZeroes = true;
				result += str[i];
			}
		}
		reverse(result.begin(), result.end());
	}
	return result;
}

bool solveAddOne(string x, string y) {
	// you cannot add 1 to front without any 1 at back
	if (x[x.length() - 1] == y[y.length() - 1] && x[x.length() - 1] == '0') return false;
	size_t found = y.find(x);
	if (found != string::npos) {
		bool invalid = false;
		for (int i = 0; i < found; i++)
			if (y[i] != '1') {
				invalid = true;
				break;
			}
		if (!invalid) for (int i = found + x.length(); i < y.length(); i++)
			if (y[i] != '1') {
				invalid = true;
				break;
			}
		if (!invalid) return true;
	}
	return false;
}

bool solve(string x, string y) {
	// x == y
	if (x == y) return true;
	if (removeLeadingZeroes(x, true) == y) return true;
	// rev(x) == y
	string xr = x;
	reverse(xr.begin(), xr.end());
	string xro = '1' + xr;
	xr = removeLeadingZeroes(xr, false);
	if (xr == y) return true;
	// rev(x) + '1' == y
	if (xro == y) return true;
	// addOne(x) == y
	if (solveAddOne(x, y)) return true;
	// addOne(rev(x)) == y
	if (solveAddOne(xr, y)) return true;
	// addOne('1' + rev(x)) == y
	if (solveAddOne(xro, y)) return true;
	return false;
}

string ull2str(unsigned long long x) {
	if (x == 0) return "0";
	string result;
	while (x) {
		if (x & 1) result += '1';
		else result += '0';
		x >>= 1;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	#ifdef VSCODE_DBG
	#endif
	unsigned long long x, y;
	cin >> x >> y;
	if (solve(ull2str(x), ull2str(y))) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
