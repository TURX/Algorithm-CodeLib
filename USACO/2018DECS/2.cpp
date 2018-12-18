#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct data {
    int num, hajime, duration, delay;
} d[100001];

int n, ans, maxOwari;

bool cmp(data lhs, data rhs) {
    if (lhs.hajime + lhs.duration != rhs.hajime + rhs.duration)
        return lhs.hajime + lhs.duration < rhs.hajime + rhs.duration;
    else
        return lhs.num < rhs.num;
}

void setDelay(int pos) {
    maxOwari = 0;
    for(int t = 0; t < pos; t++) {
        maxOwari = max(maxOwari, d[t].hajime + d[t].duration + d[t].delay);
    }
    d[pos].delay = max(maxOwari, d[pos].hajime) - d[pos].hajime;
}

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int t = 0; t < n; t++) {
        cin >> d[t].hajime >> d[t].duration;
        d[t].num = t + 1;
    }
    sort(d, d + n, cmp);
    for (int t = 0; t < n; t++) {
        setDelay(t);
        ans = max(d[t].delay, ans);
    }
    cout << ans << endl;
    return 0;
}