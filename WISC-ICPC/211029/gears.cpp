#include <iostream>
using namespace std;

int cases, N;
long long A[501], M[501];

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if (!b) { x = 1, y = 0; return a; }
	long long d = exgcd(b, a % b, x, y);
	long long z = x; x = y; y = z - y * (a / b);
	return d;
}

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
	cin >> cases;
	while (cases--) {
		bool u = true;
		cin >> N;
		long long multi = 1, gcdr, lcmr, ans = 0;
		cin >> M[0] >> A[0]; // 以这个为底，都需要能有一个与它的解
		for (int i = 1; i < N; i++) {
			cin >> M[i] >> A[i]; // x === A[i] (mod M[i])，解线性同余方程组
			long long K = A[i] - A[0];
			long long x, y;
			long long d = exgcd(M[0], M[i], x, y);
			if (K % d != 0) u = false;
			x=((x*(K/d)%(M[i]/d))+(M[i]/d))%(M[i]/d);
            b1=x*m1+b1;
            m1=m1*m2/d;

			/*
			multi *= M[i];
			if (i == 0) gcdr = M[i];
			else gcdr = gcd(gcdr, M[i]);
			*/
		}
		//lcmr = multi / gcdr;
		/*for (int i = 0; i < N; i++) {
			
		}
		cout << (ans + multi) % multi << endl;
		*/
	}
}
