// luogu-judger-enable-o2
// Segment Tree Template
// Author: TURX
// From the presentation document and https://pks-loving.blog.luogu.org/senior-data-structure-qian-tan-xian-duan-shu-segment-tree and archived code.

#include <iostream>
using namespace std;

#define lson(id) (id << 1)
#define rson(id) (id << 1 | 1)
#define mid(left, right) ((left + right) >> 1)

long long total[100003 << 2], tag[100003 << 2], k;
int N, M, operation, x, y, input[100003];

inline void preProcess(const int& id, const int& l, const int& r) {
    if(l == r) total[id] = input[l]; // Build the bottom line of nodes (original value).
    else {
        int mid = (l + r) >> 1; // Middle = (l + r) / 2.
        preProcess(lson(id), l, mid); // Build my left part recursively.
        preProcess(rson(id), mid + 1, r); // Build my right part recursively.
        total[id] = total[lson(id)] + total[rson(id)]; // Add 2 children's values to the father (#this) node.
    }
}

inline void pushDown_old(const int& id, const int& l, const int& r) {
    if(l == r) return;
    if(!tag[id]) return;
    int mid = (l + r) >> 1; // Middle = (l + r) / 2.
    tag[id << 1] += tag[id]; // Transfer my tag to my left child.
    tag[id << 1 | 1] += tag[id]; // Transfer my tag to my right child.
    total[id << 1] += tag[id] * (mid - l + 1); // Apply my tag to my left child.
    total[id << 1 | 1] += tag[id] * (r - mid + 1); // Apply my tag to my right child.
    tag[id] = 0; // Clear my tag.
}

inline void pushDown(const int& id) {
    if(!tag[id]) return;
    // l: lson(id), r: rson(id)
    int mid = mid(lson(id), rson(id));
    tag[lson(id)] += tag[id]; // Transfer my tag to my left child.
    tag[rson(id)] += tag[id]; // Transfer my tag to my right child.
    total[lson(id)] += tag[id] * (mid - lson(id) + 1);
    total[rson(id)] += tag[id] * (rson(id) - mid);
    // total[lson(id)] += tag[id] * (rson(lson(id)) - lson(lson(id)) + 1); // Apply my tag to my left child.
    // total[rson(id)] += tag[id] * (rson(rson(id)) - lson(rson(id)) + 1); // Apply my tag to my right child.
    tag[id] = 0; // Clear my tag.
}

inline void update(const int& id, const int& l, const int& r, const int& borderL, const int& borderR, const long long& val) {
    if(l < borderL || r > borderR) return;
    if(l <= borderL && r >= borderR) { // Competely covered.
        total[id] += (long long)val * (rson(id) - lson(id) + 1);
        tag[id] += val;
        return;
    }
    pushDown(id);
    int mid = mid(l, r);
    update(lson(id), l, mid, borderL, borderR, val);
    update(rson(id), mid + 1, r, borderL, borderR, val);
    total[id] = total[lson(id)] + total[rson(id)];
}

inline long long enquiry(const int& id, const int& l, const int& r, const int& borderL, const int& borderR) {
    if(l <= borderL && r >= borderR) return total[id];
    int mid = mid(borderL, borderR);
    long long res = 0;
    if(l <= mid) res += enquiry(lson(id), l, r, borderL, mid);
    if(r > mid) res += enquiry(rson(id), l, r, mid + 1, borderR);
    return res;
}

int main() {
    cin >> N >> M;
    for(int t = 1; t <= N; t++) {
        cin >> input[t];
    }
    preProcess(1, 1, N);
    while(M--) {
        cin >> operation;
        switch(operation) {
            case 1:
                cin >> x >> y >> k;
                update(1, x, y, 1, N, k);
                // update(id, l, r, borderL, borderR, val)
                break;
            case 2:
                cin >> x >> y; 
                cout << enquiry(1, x, y, 1, N) << endl;
                // enquiry(id, l, r, borderL, borderR)
                break;
        }
    }
    return 0;
}