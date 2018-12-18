#include <iostream>
using namespace std;

#define MAXN 100001
#define lson(x) x << 1
#define rson(x) x << 1 | 1
long long total[MAXN << 2], tag[MAXN << 2], input[MAXN];

inline void preProcess(const int& id, const int& l, const int& r) {
    if(l == r) total[id] = input[l]; // Build the bottom line of nodes (original value).
    else {
        int mid = (l + r) >> 1; // Middle = (l + r) / 2.
        preProcess(id << 1, l, mid); // Build my left part recursively.
        preProcess(id << 1 | 1, mid + 1, r); // Build my right part recursively.
        total[id] = min(total[id << 1], total[id << 1 | 1]); // Add 2 children's values to the father (#this) node.
    }
}

long long enquiry(const int& id, const int& l, const int& r, const int& borderL, const int& borderR) {
    if(l > borderR || r < borderL) return 0;
    if(l <= borderL && r >= borderR) return total[id];
    // Initial: borderL = 1, borderR = N, l = x, r = y;
    int mid = (borderL + borderR) >> 1;
    return min(enquiry(lson(id), l, r, borderL, mid), enquiry(rson(id), l, r, mid + 1, borderR));
}

inline int at(const int& n) {
    return n < 1 ? 1 : n;
}

int main() {
    int N, M, x, y, op;
    long long k;
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int t = 1; t <= N; t++) cin >> input[t];
    preProcess(1, 1, N);
    for(int t = 1; t < N; t++) {
        cout << enquiry(1, at(t - M), at(t), 1, N) << endl;
    }
    return 0;
}