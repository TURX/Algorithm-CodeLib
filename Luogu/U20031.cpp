%:pragma GCC optimize(2)
#include <iostream>
typedef unsigned long long ull;
using namespace std;
ull N, M, pillar[10000003], maxH = 0, total = 0;

int main() {
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for(ull t = 0; t < M; t++) {
    ull l, r, s, e, difference; //, countOfNumbers;
    cin >> l >> r >> s >> e;
    // countOfNumbers = r - l + 1;
    difference =  (e - s) / (r - l);
    for(ull i = l - 1; i < r; i++) {
      pillar[i] += s;
      s += difference;
    }
  }
  for(ull t = 0; t < N; t++) {
    maxH = max(maxH, pillar[t]);
    total ^= pillar[t];
  }
  cout << total << " " << maxH << endl;
  return 0;
}
