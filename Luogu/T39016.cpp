#include <iostream>
using namespace std;
int a[1000003], n, m, seed;

inline void generate_array() {
    unsigned x = seed;
    for (int i = 0; i < n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a[i] = x % m + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> seed;
    generate_array();
}