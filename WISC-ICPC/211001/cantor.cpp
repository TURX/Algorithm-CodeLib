#include <iostream>
using namespace std;

double N;

bool contour(double l, double r) {
	if (r - l < 0.000001) return true;
	else {
		double delta = (r - l) / 3;
		if (N > l + delta && N < r - delta) return false;
		else {
			if (N <= l + delta) return contour(l, l + delta);
			else return contour(r - delta, r);
		}
	}
}

int main() {
	// freopen("test.in", "r", stdin);
	while (cin >> N) {
		if (contour(0, 1)) cout << "MEMBER" << endl;
		else cout << "NON-MEMBER" << endl;
	}
}
