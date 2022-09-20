#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int Z = N - 1; // z = a + b, c = 1
		int ZZ;
		int A, B;
		if (Z % 2) {
			// z is odd, z = 2 * i + (2 * j + 1) = 2 * i + (2 * i + 1)
			A = Z / 2;
			B = A + 1;
		} else {
			// z is even, z = (2 * i + 1) + (2 * j + 1) = (2 * i + 1) + (2 * i + 3)
			ZZ = Z / 2;
			if (ZZ % 2) {
				// z / 2 is odd
				A = Z / 2 - 2;
				B = Z / 2 + 2;
			} else {
				// z / 2 is even
				A = Z / 2 - 1;
				B = Z / 2 + 1;
			}
		}
		cout << A << " " << B << " 1" << endl;
	}
	return 0;
}
