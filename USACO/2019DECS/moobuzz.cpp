#include <iostream>
#include <cstdio>
using namespace std;

unsigned long long N;

int getInLine(int x) {
	switch (x) {
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 4;
		case 4:
			return 7;
		case 5:
			return 8;
		case 6:
			return 11;
		case 7:
			return 13;
	}
	return 0;
}

int main() {
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
	cin >> N;
	// cout << N - ((unsigned long long)(N / 3) + (unsigned long long)(N / 5) - (unsigned long long)(N / 15)) << endl;
	// cout << N * 15 / 8 << endl;
	if (N % 8 == 0) {
		cout << (N / 8) * 15 - 1 << endl;
		return 0;
	} 
	cout << (N / 8) * 15 + getInLine(N % 8) << endl;
	return 0;
}