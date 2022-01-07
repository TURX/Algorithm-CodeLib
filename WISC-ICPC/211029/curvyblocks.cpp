#include <iostream>
#include <cmath>
using namespace std;

double b0, b1, b2, b3, t0, t1, t2, t3, a, b, c, x1, x2, y;

inline double D(double x) {
	return (t0-b0) + (t1-b1)*x + (t2-b2)*x*x + (t3-b3)*x*x*x;
}

inline double DD(double x) {
	return (t0-b0-y) + (t1-b1)*x + (t2-b2)*x*x + (t3-b3)*x*x*x;
}

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	while (cin >> b0 >> b1 >> b2 >> b3 >> t0 >> t1 >> t2 >> t3) {
		// to solve (t1-b1)+2x(t2-b2)+3x^2(t3-b3) = 0
		// which is 3(t3-b3)*x^2 + 2(t2-b2)*x + (t1-b1) = 0
		a = 3*(t3-b3);
		b = 2*(t2-b2);
		c = t1-b1;
		x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
		x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
		if (x1 < 0 || x1 > 1) x1 = 0;
		if (x2 < 0 || x2 > 1) x2 = 0;
		if (x1 == x1 && x2 == x2) {
			y = min(D(x1), min(D(x2), min(D(0), D(1))));
			printf("%.6f\n", max(DD(x1), max(DD(x2), max(DD(0), DD(1)))));
		} else {
			if (x1 == x1) {
				y = min(D(x1), min(D(0), D(1)));
				printf("%.6f\n", max(DD(x1), max(DD(0), DD(1))));
			}
			else if (x2 == x2) {
				y = min(D(x2), min(D(0), D(1)));
				printf("%.6f\n", max(DD(x2), max(DD(0), DD(1))));
			}
			else {
				y = min(D(0), D(1));
				printf("%.6f\n", max(DD(0), DD(1)));
			}
		}
	}
}
