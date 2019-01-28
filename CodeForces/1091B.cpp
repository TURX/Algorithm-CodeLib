#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100003

int N;

struct Position {
    long long x, y;
    inline bool operator< (const Position& comp) {
        return x == comp.x ? y > comp.y : x > comp.x;
    }
} I[MAXN], J[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 1; t <= N; t++) cin >> I[t].x >> I[t].y;
    for(int t = 1; t <= N; t++) cin >> J[t].x >> J[t].y;
    sort(I + 1, I + N + 1);
    sort(J + 1, J + N + 1);
    cout << I[1].x + J[N].x << ' ' << I[1].y + J[N].y << endl;
    return 0;
}