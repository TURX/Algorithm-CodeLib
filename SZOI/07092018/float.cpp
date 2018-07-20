#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    float a;
    cin >> a;
    char c[1000];
    sprintf(c, "%.4f", a);
    c[strlen(c) - 1] = 0;
    printf("%s\n", c);
    cout << endl;
    return 0;
}