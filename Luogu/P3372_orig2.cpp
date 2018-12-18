// luogu-judger-enable-o2
// Segment Tree Template
// Author: TURX
// From the presentation document and https://pks-loving.blog.luogu.org/senior-data-structure-qian-tan-xian-duan-shu-segment-tree and archived code.

#include <iostream>
using namespace std;

long long total[100003 << 2], tag[100003 << 2], k;
int N, M, operation, x, y, input[100003];

inline void preProcess(const int& id, const int& l, const int& r) {
    if(l == r) total[id] = input[l]; // Build the bottom line of nodes (original value).
    else {
        int mid = (l + r) >> 1; // Middle = (l + r) / 2.
        preProcess(id << 1, l, mid); // Build my left part recursively.
        preProcess(id << 1 | 1, mid + 1, r); // Build my right part recursively.
        total[id] = total[id << 1] + total[id << 1 | 1]; // Add 2 children's values to the father (#this) node.
    }
}

inline void pushDown(const int& id, const int& l, const int& r) {
    // if(l == r) return;
    if(!tag[id]) return;
    int mid = (l + r) >> 1; // Middle = (l + r) / 2.
    tag[id << 1] += tag[id]; // Transfer my tag to my left child.
    tag[id << 1 | 1] += tag[id]; // Transfer my tag to my right child.
    total[id << 1] += tag[id] * (mid - l + 1); // Apply my tag to my left child.
    total[id << 1 | 1] += tag[id] * (r - mid); // Apply my tag to my right child.
    tag[id] = 0; // Clear my tag.
}

inline void update(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR, const long long& val) {
    if(currentIntervalR < l  || currentIntervalL > r) return; // Deal with the problem that the update interval is out of range.
    if(currentIntervalL >= l && currentIntervalR <= r) { // Update between currentIntervalL and currentIntervalR.
        total[id] += val * (currentIntervalR - currentIntervalL + 1); // Apply required value to myself.
        tag[id] += val; // Transfer the value modification via modify the tag.
        return;
    }
    pushDown(id, currentIntervalL, currentIntervalR); // Apply the tag modification to 2 children.
    int mid = (currentIntervalL + currentIntervalR) >> 1; // Middle = (l + r) / 2.
    update(id << 1, l, r, currentIntervalL, mid, val); // Update the left interval. (Split procedures)
    update(id << 1 | 1, l, r, mid + 1, currentIntervalR, val); // Update the right interval. (Split procedures)
    total[id] = total[id << 1] + total[id << 1 | 1]; // Apply modified sum back to me.
}

inline long long enquiry(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR) {
    // if(l > currentIntervalL || r < currentIntervalR) return 0;
    if(l <= currentIntervalL && r >= currentIntervalR) return total[id];
    pushDown(id, l, r);
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    return enquiry(id << 1, l, r, currentIntervalL, mid) + enquiry(id << 1 | 1, l, r, mid + 1, currentIntervalR);
}

inline long long enquiry_2(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR) {
    if(l > currentIntervalR || r < currentIntervalL) return 0;
    long long res = 0;
    if(l <= currentIntervalL && r >= currentIntervalR) return total[id];
    long long mid = (currentIntervalL + currentIntervalR) >> 1;
    pushDown(id, currentIntervalL, currentIntervalR);
    res += enquiry_2(id << 1, l, r, currentIntervalL, mid);
    res += enquiry_2(id << 1 | 1, l, r, mid + 1, currentIntervalR);
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
                // update(id, l, r, currentIntervalL, currentIntervalR, val)
                break;
            case 2:
                cin >> x >> y;
                cout << enquiry_2(1, x, y, 1, N) << endl;
                // enquiry(id, l, r, currentIntervalL, currentIntervalR)
                break;
        }
    }
    return 0;
}