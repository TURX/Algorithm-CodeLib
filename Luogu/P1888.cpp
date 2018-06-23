#define na num[0]
#define nb num[2]
#include <iostream>
#include <algorithm>
using namespace std;

int num[3];
int main() {
  ios::sync_with_stdio(false);
  cin >> num[0] >> num[1] >> num[2];
  sort(num, num + 3);
  for(int i = 1; i < na; i++) {
    if(na % i == 0 && nb % i == 0) {
      na /= i;
      nb /= i;
    }
  }
  cout << na << "/" << nb << endl;
  return 0;
}
