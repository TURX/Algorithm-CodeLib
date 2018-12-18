#include <iostream>
using namespace std;
template T;
int n, to[200003];

struct unionFindSet {
  int ufset[200003];
  inline void init(const T& n) {
    for(int t = 0; t < (int)n; t++) ufset[t] = t;
  }
  /*
  inline T find(const T& n) {
    int c = (int)n, t;
    // while(ufset[c] != c) c = ufset[c];
    while((int)n != c) {
      t = ufset[(int)n];
      ufset[(int)n] = c;
      n = t;
    }
    return n;
  }
  */
 
} ufset;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for(int t = 0; t < n; t++) {
    cin >> to[t];
  }
  return 0;
}
