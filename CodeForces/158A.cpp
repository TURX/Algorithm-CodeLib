#include <iostream>
using namespace std;
int n, k, a[103], score, trueK, errp = 104;

int main() {
  cin >> n >> k;
  for(int t = 0; t < n; t++) cin >> a[t];
  score = a[k - 1];
  for(int t = 0; ; t++) {
    trueK = t;
    if(a[t] < score) break;
    if(a[t] == 0) {
      errp = t;
      break;
    }
  }
  cout << (errp == 0 ? 0 : trueK) << endl;
  return 0;
}
