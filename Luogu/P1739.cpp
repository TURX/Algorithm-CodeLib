#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	char now;
	int statistics=0;
	ios::sync_with_stdio(false);
	while (now != '@') {
		now = getchar();
		if (now == '(') statistics++;
		if (now == ')') {
			if (statistics) statistics--;
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if (!statistics) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
