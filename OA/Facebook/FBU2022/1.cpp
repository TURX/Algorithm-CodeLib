#include <iostream>
using namespace std;

int threeCharsDistinct(string s) {
    int ans = 0;
    if (s.length() >= 3) {
		for (int i = 0; i < s.length() - 2; i++) {
			if ((s.at(i) != s.at(i + 1)) && (s.at(i) != s.at(i + 2)) && (s.at(i + 1) != s.at(i + 2))) {
				ans++;
			}
		}
	}
    return ans;
}

int main() {
	cout << threeCharsDistinct("o") << endl;
	return 0;
}