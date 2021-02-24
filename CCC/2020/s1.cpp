#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
long double S = 0;

struct D {
	int T, X;
	inline friend bool operator <(const D& lhs, const D& rhs) {
        return lhs.T < rhs.T;
    }
} A[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].T >> A[i].X;
	}
	sort(A, A + N);
	for (int i = 0; i < N - 1; i++) {
		S = max(S, (long double)abs(A[i + 1].X - A[i].X) / (A[i + 1].T - A[i].T));
	}
	cout << S << endl;
	return 0;
}
