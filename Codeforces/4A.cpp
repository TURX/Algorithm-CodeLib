#include <iostream>
using namespace std;
int w;

int main() {
  cin >> w;
  if(w != 2) cout << (w % 2 ? "NO" : "YES") << endl;
  else cout << "NO" << endl;
  return 0;
}
