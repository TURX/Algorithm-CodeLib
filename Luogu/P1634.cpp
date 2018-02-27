#include <iostream>
#include <cmath>
using namespace std;
long long x, n, s = 1;

int main() {
  cin >> x >> n;
  for(int i = 0; i < n; i++) {
    s += s * x;
  }
  cout << s << endl;
  return 0;
}
