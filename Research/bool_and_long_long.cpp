#include <iostream>
using namespace std;
int main() {
  int a=666;
  void *t=&a;
  cout<<bool(((bool*)t)[0])<<endl;
  return 0;
}
