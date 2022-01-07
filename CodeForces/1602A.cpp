#include <iostream>
using namespace std;

int T;
string S;

int main() {
	cin >> T;
	while (T--) {
		cin >> S;
		int pos = 0;
		for (int i = 0; i < S.length(); i++) {
			if (S.at(pos) > S.at(i)) pos = i;
		}
		cout << S.at(pos) << " ";
		for (int i = 0; i < S.length(); i++) {
			if (i != pos) cout << S.at(i);
		}
		cout << endl;
	}
}
