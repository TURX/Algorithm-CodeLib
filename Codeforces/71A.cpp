#include <iostream>
#include <string>
using namespace std;
int n;
string str;

int main() {
  cin >> n;
  for(int t = 0; t < n; t++) {
    cin >> str;
    if(str.length() <= 10) cout << str << endl;
    else cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
  }
  return 0;
}
