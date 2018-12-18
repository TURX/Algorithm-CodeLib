#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000001
#define lson(x) x << 1
#define rson(x) x << 1 | 1
long long globRes[MAXN << 2], tag[MAXN << 2], input[MAXN];

inline void preProcess(const int& id, const int& l, const int& r) {
    if(l == r) globRes[id] = input[l]; // Build the bottom line of nodes (original value).
    else {
        int mid = (l + r) >> 1; // Middle = (l + r) / 2.
        preProcess(id << 1, l, mid); // Build my left part recursively.
        preProcess(id << 1 | 1, mid + 1, r); // Build my right part recursively.
        globRes[id] = min(globRes[id << 1], globRes[id << 1 | 1]);
    }
}

inline void pushDown(const int& id, const int& currentIntervalL, const int& currentIntervalR) {
    if(!tag[id]) return;
    tag[lson(id)] += tag[id];
    tag[rson(id)] += tag[id];
    globRes[lson(id)] += tag[id];
    globRes[rson(id)] += tag[id];
    tag[id] = 0;
}

void update(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR, const long long& val) {
    if(l > currentIntervalR || r < currentIntervalL) return;
    if(l <= currentIntervalL && r >= currentIntervalR) {
        globRes[id] += val;
        tag[id] += val;
        return;
    }
    pushDown(id, currentIntervalL, currentIntervalR);
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    update(lson(id), l, r, currentIntervalL, mid, val);
    update(rson(id), l, r, mid + 1, currentIntervalR, val);
    globRes[id] = min(globRes[lson(id)], globRes[rson(id)]);
}

long long enquiry(const int& id, const int& l, const int& r, const int& borderL, const int& borderR) {
    if(l > borderR || r < borderL) return 0;
    if(l <= borderL && r >= borderR) return globRes[id];
    pushDown(id, borderL, borderR);
    int mid = (borderL + borderR) >> 1;
    return min(enquiry(lson(id), l, r, borderL, mid), enquiry(rson(id), l, r, mid + 1, borderR));
}

int main() {
    int N, M, x, y;
    long long k;
    memset(globRes, INT32_MAX, sizeof(globRes));
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int t = 1; t <= N; t++) cin >> input[t];
    preProcess(1, 1, N);
    for(int t = 1; t <= M; t++) {
        cin >> k >> x >> y;
        update(1, x, y, 1, N, -k);
        if(enquiry(1, 1, N, 1, N) < 0) {
            cout << "-1" << endl;
            cout << t << endl;
            return 0;
        }
    }
    cout << "0" << endl;
    return 0;
}