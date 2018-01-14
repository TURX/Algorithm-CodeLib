#include <iostream>
#include <string>
using namespace std;
int l, r, resu;
int count(string x) {
    int resul=0;
    for(int t=0;t<x.length();t++) {
        if(x[t]=='2') resul++;
    }
    return resul;
}
int main() {
    cin >>  l >> r;
    for(;l<=r;l++) {
        resu+=count(to_string(l));
    }
    cout << resu << endl;
}