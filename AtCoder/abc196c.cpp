#include <iostream>
using namespace std;

int genNine(unsigned int n) {
	int ans = 0;
	while (n--) {
		ans *= 10;
		ans += 9;
	}
	return ans;
}

int main() {
	string n;
	cin >> n;
	if (n.length() % 2) cout << genNine(n.length() / 2) << endl;
	else {
		int a = stoi(n.substr(0, n.length() / 2)), b = stoi(n.substr(n.length() / 2, n.length()));
		if (a <= b) cout << a << endl;
		else cout << a - 1 << endl;
	}
}
