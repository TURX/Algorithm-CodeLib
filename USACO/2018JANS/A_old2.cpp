#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int N, a, b, ans, fact[1000003];

int factorial(const int& n) {
    if(fact[n]) return fact[n];
    int t = factorial(n - 1) * n;
    fact[n] = t;
    return t;
}

int C(const int& n, const int& k) {
    return factorial(n) / (factorial(n - k) * factorial(k));
}

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 0; t < N - 1; t++) {
        cin >> a >> b;
    }
    fact[1] = 1, fact[2] = 2;
    cout << C(N, 2) - C(N - 1, 2) << endl;
    return 0;
}