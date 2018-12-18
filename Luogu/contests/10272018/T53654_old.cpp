#include <iostream>
#include <string>
using namespace std;

#define MAXN 200003
#define lson(x) x << 1
#define rson(x) x << 1 | 1

int N, K, T[MAXN];
long long total[MAXN << 2], tag[MAXN << 2], input[MAXN], maxNumber = -__LONG_LONG_MAX__;

inline void preProcess(const int& id, const int& l, const int& r) {
    if(l == r) total[id] = input[l]; // Build the bottom line of nodes (original value).
    else {
        int mid = (l + r) >> 1; // Middle = (l + r) / 2.
        preProcess(id << 1, l, mid); // Build my left part recursively.
        preProcess(id << 1 | 1, mid + 1, r); // Build my right part recursively.
        total[id] = total[id << 1] + total[id << 1 | 1]; // Add 2 children's values to the father (#this) node.
    }
}

inline void pushDown(const int& id, const int& currentIntervalL, const int& currentIntervalR) {
    if(!tag[id]) return;
    tag[lson(id)] += tag[id];
    tag[rson(id)] += tag[id];
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    total[lson(id)] += tag[id] * (mid - currentIntervalL + 1);
    total[rson(id)] += tag[id] * (currentIntervalR - mid);
    tag[id] = 0;
}

void update(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR) {
    if(l > currentIntervalR || r < currentIntervalL) return;
    if(l <= currentIntervalL && r >= currentIntervalR) {
        total[id] = 1 * (currentIntervalR - currentIntervalL + 1);
        tag[id] = 1;
        return;
    }
    pushDown(id, currentIntervalL, currentIntervalR);
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    update(lson(id), l, r, currentIntervalL, mid);
    update(rson(id), l, r, mid + 1, currentIntervalR);
    total[id] = total[lson(id)] + total[rson(id)];
}

long long enquiry(const int& id, const int& l, const int& r, const int& borderL, const int& borderR) {
    if(l > borderR || r < borderL) return 0;
    if(l <= borderL && r >= borderR) return total[id];
    long long ans = 0;
    pushDown(id, borderL, borderR);
    int mid = (borderL + borderR) >> 1;
    ans += enquiry(lson(id), l, r, borderL, mid);
    ans += enquiry(rson(id), l, r, mid + 1, borderR);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int t = 0; t < N; t++) cin >> input[t];
    for(int t = 0; t < N; t++) cin >> T[t];
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            maxNumber = max(maxNumber, enquiry(1, i, j, 1, N));
        }
    }
    return 0;
}