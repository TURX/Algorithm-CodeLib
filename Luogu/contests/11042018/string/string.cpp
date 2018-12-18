#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int a, b, c, d;
unsigned long long ans;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    cout << a * (b + c) << endl;
}