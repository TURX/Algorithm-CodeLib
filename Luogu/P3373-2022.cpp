#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cassert>
using namespace std;

void brk() {}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

int mod;

// assume -mod <= x < 2 * mod
int norm(int x) {
  if (x < 0) {
    x += mod;
  }
  if (x >= mod) {
    x -= mod;
  }
  return x;
}

template <class T>
T power(T a, int b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

struct mint {
  int x;
  mint(int x = 0) : x(norm(x)) {}
  int val() const { return x; }
  mint operator-() const { return mint(norm(mod - x)); }
  mint inv() const {
    // assume x != 0
    return power(*this, mod - 2);
  }
  mint &operator*=(const mint &rhs) {
    x = (ll)x * rhs.x % mod;
    return *this;
  }
  mint &operator+=(const mint &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res *= rhs;
    return res;
  }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res += rhs;
    return res;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res -= rhs;
    return res;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res /= rhs;
    return res;
  }
};

typedef vector<mint> vm;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	mint madd = 0, mmul = 1, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of 0
	Node(vm& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = l->val + r->val;
		}
		else val = v[lo];
	}
	mint query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void add(int L, int R, mint x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x * (hi - lo);
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = l->val + r->val;
		}
	}
	void mul(int L, int R, mint x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (madd.val() != 0) madd *= x;
			mmul *= x;
			val *= x;
		}
		else {
			push(), l->mul(L, R, x), r->mul(L, R, x);
			val = l->val + r->val;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		else {
			if (mmul.val() != 1)
				l->mul(lo,hi,mmul), r->mul(lo,hi,mmul), mmul = 1;
			if (madd.val() != 0)
				l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
		}
	}
};

Node* tr;

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int N, M, x, y, op, k;
	cin >> N >> M >> mod;
	vm A(N);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A[i] = mint(tmp);
	}
	tr = new Node(A, 0, sz(A));
	while (M--) {
		cin >> op;
		switch (op) {
			case 1:
				cin >> x >> y >> k;
				tr->mul(x - 1, y, k);
				break;
			case 2:
				cin >> x >> y >> k;
				tr->add(x - 1, y, k);
				break;
			case 3:
				cin >> x >> y;
				cout << tr->query(x - 1, y).val() << endl;
				break;
		}
	}
	return 0;
}
