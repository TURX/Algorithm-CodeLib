#include <iostream>
using namespace std;

#define MAXN 100001
#define lson(x) x << 1
#define rson(x) x << 1 | 1
long long total[MAXN << 2], tagAdd[MAXN << 2], tagMulti[MAXN << 2], input[MAXN];

inline void preProcess(const int& id, const int& l, const int& r) {
    if(l == r) total[id] = input[l]; // Build the bottom line of nodes (original value).
    else {
        int mid = (l + r) >> 1; // Middle = (l + r) / 2.
        preProcess(id << 1, l, mid); // Build my left part recursively.
        preProcess(id << 1 | 1, mid + 1, r); // Build my right part recursively.
        total[id] = total[id << 1] + total[id << 1 | 1]; // Add 2 children's values to the father (#this) node.
    }
}

inline void pushDownAdd(const int& id, const int& currentIntervalL, const int& currentIntervalR) {
    if(!tagAdd[id]) return;
    tagAdd[lson(id)] += tagAdd[id];
    tagAdd[rson(id)] += tagAdd[id];
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    total[lson(id)] += tagAdd[id] * (mid - currentIntervalL + 1);
    total[rson(id)] += tagAdd[id] * (currentIntervalR - mid);
    tagAdd[id] = 0;
}

void updateAdd(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR, const long long& val) {
    if(l > currentIntervalR || r < currentIntervalL) return;
    if(l <= currentIntervalL && r >= currentIntervalR) {
        total[id] += val * (currentIntervalR - currentIntervalL + 1);
        tagAdd[id] += val;
        return;
    }
    pushDownAdd(id, currentIntervalL, currentIntervalR);
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    updateAdd(lson(id), l, r, currentIntervalL, mid, val);
    updateAdd(rson(id), l, r, mid + 1, currentIntervalR, val);
    total[id] = total[lson(id)] + total[rson(id)];
}

inline void pushDownMulti(const int& id, const int& currentIntervalL, const int& currentIntervalR) {
    if(!tagMulti[id]) return;
    tagMulti[lson(id)] *= tagMulti[id];
    tagMulti[rson(id)] *= tagMulti[id];
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    total[lson(id)] *= tagMulti[id] * (mid - currentIntervalL + 1);
    total[rson(id)] *= tagMulti[id] * (currentIntervalR - mid);
    tagAdd[id] = 0;
}

void updateMulti(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR, const long long& val) {
    if(l > currentIntervalR || r < currentIntervalL) return;
    if(l <= currentIntervalL && r >= currentIntervalR) {
        total[id] *= val * (currentIntervalR - currentIntervalL + 1);
        tagAdd[id] *= val;
        return;
    }
    pushDownMulti(id, currentIntervalL, currentIntervalR);
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    updateMulti(lson(id), l, r, currentIntervalL, mid, val);
    updateMulti(rson(id), l, r, mid + 1, currentIntervalR, val);
    total[id] = total[lson(id)] * total[rson(id)];
}

long long enquiry(const int& id, const int& l, const int& r, const int& borderL, const int& borderR) {
    if(l > borderR || r < borderL) return 0;
    if(l <= borderL && r >= borderR) return total[id];
    // Initial: borderL = 1, borderR = N, l = x, r = y;
    long long ans = 0;
    pushDownMulti(id, borderL, borderR);
    pushDownAdd(id, borderL, borderR);
    int mid = (borderL + borderR) >> 1;
    ans += enquiry(lson(id), l, r, borderL, mid);
    ans += enquiry(rson(id), l, r, mid + 1, borderR);
    return ans;
}

int main() {
    int N, M, x, y, op;
    long long k;
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int t = 1; t <= N; t++) cin >> input[t];
    preProcess(1, 1, N);
    while(M--) {
        cin >> op;
        switch(op) {
            case 1:
                cin >> x >> y >> k;
                updateMulti(1, x, y, 1, N, k);
            case 2:
                cin >> x >> y >> k;
                updateAdd(1, x, y, 1, N, k);
                break;
            case 3:
                cin >> x >> y;
                cout << enquiry(1, x, y, 1, N) << endl;
                break;
        }
    }
    return 0;
}