constexpr int mod = 1e9 + 7;

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
