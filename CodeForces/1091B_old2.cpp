#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 200003

int N;

struct Position {
    long long x, y;
    inline bool operator< (const Position& comp) {
        return x == comp.x ? y > comp.y : x > comp.x;
    }
} I[MAXN], ans;

inline Position add(const Position& l, const Position& r) {
    Position ans;
    ans.x = l.x + r.x;
    ans.y = l.y + r.y;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 1; t <= (N << 1); t++) cin >> I[t].x >> I[t].y;
    sort(I + 1, I + (N << 1) + 1);
    for(int t = 1; t <= (N >> 1); t++) {
        ans = add(ans, I[t]);
    }
    for(int t = (N << 1); t > (N << 1) - (N >> 1); t--) {
        ans = add(ans, I[t]);
    }
    cout << ans.x / (N >> 1) << ' ' << ans.y / (N >> 1) << endl;
    return 0;
}