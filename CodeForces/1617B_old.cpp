#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM = 1e9;
bitset<LIM> isPrime;

vi eratosthenes() {
	const int S = 31623, R = LIM / 2;
	vi pr = {2}, sieve(S + 1);
	pr.reserve(int(LIM / log(LIM) * 1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2)
		if (!sieve[i]) {
			cp.push_back({i, i * i / 2});
			for (int j = i * i; j <= S; j += 2 * i)
				sieve[j] = 1;
		}
	for (int L = 1; L <= R; L += S) {
		array<bool, S> block{};
		for (auto &[p, idx] : cp)
			for (int i = idx; i < S + L; idx = (i += p))
				block[i - L] = 1;
		rep(i, 0, min(S, R - L)) if (!block[i]) pr.push_back((L + i) * 2 + 1);
	}
	for (int i : pr)
		isPrime[i] = 1;
	return pr;
}

ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1)
			ans = modmul(ans, b, mod);
	return ans;
}

bool isPrimeP(ull n) {
	if (n < 2 || n % 6 % 4 != 1)
		return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
		s = __builtin_ctzll(n - 1), d = n >> s;
	for (ull a : A) { // ^ count trai l ing zeroes
		ull p = modpow(a % n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n - 1 && i != s)
			return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y)
			x = ++i, y = f(x);
		if ((q = modmul(prd, max(x, y) - min(x, y), n)))
			prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}

vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrimeP(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N % 3 == 0) { // N / 3
			int ans = N / 3;
			cout << ans << " " << ans << " " << ans << endl;
			continue;
		}
		vector<ull> F = factor(N); // factorize N
		for (ull c : F) {
			// prime1 * c + prime2 * c + c = n (c >= 1)
			// === c * (prime1 + prime2 + 1) = n (a == )
		}
	}
}
