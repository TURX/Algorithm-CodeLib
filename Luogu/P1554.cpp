#include <iostream>
#include <string>
using namespace std;
int l, r, resu[10];
void count(string x) {
    for(int t=0;t<x.length();t++) {
        resu[x[t]-'0']++;
    }
}
int main() {
    cin >>  l >> r;
    for(;l<=r;l++) {
        count(to_string(l));
    }
    for(int t=0;t<10;t++) cout << resu[t] << " ";
    cout << endl;
}