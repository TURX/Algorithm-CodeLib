#include <iostream>
using namespace std;

int main() {
	int w = 0, b = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'W') w++;
		else b++;
	cout << (w == b ? 1 : 0) << endl;
}
