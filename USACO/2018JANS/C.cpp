#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

struct Mountain {
    long long left, right;
};
vector<Mountain> mounts;

int N, ans;
long long x, y;

inline bool check(const int& t) {
    for(int i = 0; i < mounts.size(); i++) {
        if(i == t) continue;
        if(mounts[i].left >= mounts[t].left && mounts[i].right <= mounts[t].right) return false;
    }
    return true;
}

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 0; t < N; t++) {
        cin >> x >> y;
        mounts.push_back({x - y, x + y});
    }
    for(int t = 0; t < mounts.size(); t++) {
        if(check(t)) ans++;
    }
    cout << ans << endl;
    return 0;
}