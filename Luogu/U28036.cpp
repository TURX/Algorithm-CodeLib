#include <iostream>
using namespace std;

unsigned n, Q, x, y;
unsigned long long sequence[100003][2003];

inline void update(const unsigned& a, const unsigned layer) {
    if(sequence[a][layer] == 0 || sequence[a % (n + 1)][layer] == 0) {
        if(sequence[a][layer] == 0) sequence[a][layer] = sequence[a][layer - 1];
        if(sequence[a % (n + 1)][layer] == 0) sequence[a % (n + 1)][layer] = sequence[a % (n + 1)][layer - 1];
    }
    if(sequence[a][layer] != sequence[a][0] && sequence[a % (n + 1)][layer] != sequence[a % (n + 1)][0]) return;
    sequence[a][layer] += sequence[a % (n + 1)][layer];
    update(a % (n + 1), layer + 1);
    update(a, layer + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(unsigned t = 0; t < n; t++) {
        cin >> sequence[t][0];
        sequence[t][1] = sequence[t][0];
    }
    cin >> Q;
    for(unsigned t = 0; t < Q; t++) {
        cin >> x >> y;
        for(unsigned i = 1; i <= x; i++) {
            update(y, i);
            cout << sequence[y][x] % 998244353 << endl;
        }
    }
    return 0;
}