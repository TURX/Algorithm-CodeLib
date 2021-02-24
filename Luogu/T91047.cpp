#include <iostream>
using namespace std;

const int MAXN = 100001;

int N, M;

struct Motion {
    int O, B;
} I[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int t = 0; t < N; t++) cin >> I[t].O;
    for (int t = 0; t < M; t++) cin >> I[t].B;
    return 0;
}