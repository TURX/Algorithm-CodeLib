#include <iostream>
#include <cmath>
using namespace std;
unsigned long long n, m, a;
int main() {
  cin >> n >> m >> a;
  cout << (unsigned long long)(ceil((double)n / a) * ceil((double)m / a)) << endl;
  return 0;
}
