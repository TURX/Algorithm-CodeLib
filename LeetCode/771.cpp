#include <iostream>
#include <string>
using namespace std;
string J, S;

int main() {
  cin >> J >> S;
  int countJ = 0;
  for(int t = 0; t < S.length(); t++) {
  	if(J.find(S[t]) != -1) {
  		countJ++;
	  }
  }
  cout << countJ << endl;
  return 0;
}
