#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100001
#define lson(x) x << 1
#define rson(x) x << 1 | 1
long long globRes[MAXN << 2], tag[MAXN << 2], input[MAXN];

inline void preProcess(const int& id, const int& l, const int& r) {
    if(l == r) {
        globRes[id] = input[l];
        tag[id] = globRes[id];
    } else {
        int mid = (l + r) >> 1; // Middle = (l + r) / 2.
        preProcess(id << 1, l, mid); // Build my left part recursively.
        preProcess(id << 1 | 1, mid + 1, r); // Build my right part recursively.
        globRes[id] = globRes[id << 1] + globRes[id << 1 | 1];
        tag[id] = max(tag[lson(id)], tag[rson(id)]);
    }
}

long long enquiry(const int& id, const int& l, const int& r, const int& borderL, const int& borderR) {
    if(l > borderR || r < borderL) return 0;
    if(l <= borderL && r >= borderR) return globRes[id];
    int mid = (borderL + borderR) >> 1;
    return enquiry(lson(id), l, r, borderL, mid) + enquiry(rson(id), l, r, mid + 1, borderR);
}

void update(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR) {
    if(l > currentIntervalR || r < currentIntervalL) return;
    if(tag[id] <= 1) return;
    if(l <= currentIntervalL && r >= currentIntervalR) {
        globRes[id] = sqrt((long double)globRes[id]);
        tag[id] = globRes[id];
        return;
    }
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    update(lson(id), l, r, currentIntervalL, mid);
    update(rson(id), l, r, mid + 1, currentIntervalR);
    globRes[id] = globRes[lson(id)] + globRes[rson(id)];
    tag[id] = max(tag[lson(id)], tag[rson(id)]);
}

int main() {
    bool op;
    int N, M, x, y, casNum = 1;
    long long k;
    ios::sync_with_stdio(false);
    while(cin >> N && N != EOF) {
        memset(globRes, 0, sizeof(globRes));
        memset(tag, 0, sizeof(tag));
        cout << "Case #" << casNum++ << ":" << endl;
        for(int t = 1; t <= N; t++) cin >> input[t];
        cin >> M;
        preProcess(1, 1, N);
        while(M--) {
            cin >> op >> x >> y;
            if(y < x) swap(x, y);
            switch(op) {
                case 0:
                    update(1, x, y, 1, N);
                    break;
                case 1:
                    cout << enquiry(1, x, y, 1, N) << endl;
                    break;
            }
        }
        cout << endl;
    }
    return 0;
}