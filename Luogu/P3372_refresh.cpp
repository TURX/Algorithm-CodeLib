// Refresh Version from failure in debugging for a month...

typedef long long LL;
#include <iostream>
using namespace std;

int op, N, M, x, y;
LL k, input[100003], total[100003 << 2];

void buildTree(const int& id, const int& l, const int& r) {
    if(l == r) total[id] = input[l];
    else {
        int mid = (l + r) >> 1; // Middle = (l + r) / 2
        buildTree(id << 1, l, mid); // Build left part
        buildTree(id << 1 | 1, mid + 1, r); // Build right part
        total[id] = total[id << 1] + total[id << 1 | 1];
    }
}

inline void update(const int& id, const int& l, const int& r, const int& borderL, const int& borderR, const long long& val) {
    if(l > borderR || r < borderL) return;
    if(l >= borderL && r <= borderR) {
        total[id] += val * (r - l + 1);
        tag[id] += val;
        return;
    }
    pushDown(id, l, r);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, borderL, borderR, val);
    update(id << 1 | 1, mid + 1, r, borderL, borderR, val);
    total[id] = total[id << 1] + total[id << 1 | 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int t = 0; t < N; t++) cin >> input[t];
    buildTree(1, 1, N);
    while(M--) {
        cin >> op;
        switch(op) {
            case 0:
                cin >> x >> y >> k;
                break;
            case 1:
                cin >> x >> y;
                break;
        }
    }
    return 0;
}