#include <iostream>
#include <map>
using namespace std;

int main() {
	freopen("4-3.txt", "r", stdin);
	//4-0: no AA (153)
	//4-1: no aaa (48)
	//4-2: no abcd (24)
	//4-3: no abab (12)
	//4-4: aabb
	freopen("4-4.txt", "w", stdout);
	string S;
	while (cin >> S) {
		map<char, int> freq;
		int flag = 0;
		bool flag2 = false; // abab
		for (int i = 0; i < S.length(); i++) {
			freq[S[i]]++;
			if (i > 0 && S[i] == S[i-1]) flag2 = true;
		}
		for (char i = 'a'; i <= 'd'; i++) {
			if (freq[i] == 2) {
				flag++;
			}
		}
		if (!(flag == 2 && flag2 == true)) cout << S << endl;
	}
}
