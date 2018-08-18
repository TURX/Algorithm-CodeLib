// Segment Tree Template
// From the presentation document and https://pks-loving.blog.luogu.org/senior-data-structure-qian-tan-xian-duan-shu-segment-tree and archived code.

#include <iostream>
using namespace std;

long long total[4 * 100003], tag[4 * 100003], k;
int N, M, operation, x, y, input[100003];

inline void preProcess(const int& id, const int& l, const int& r) {
    if(l == r) total[id] = input[l];
    else {
        int mid = (l + r) >> 1;
        preProcess(id << 1, l, mid);
        preProcess(id << 1 | 1, mid + 1, r);
        total[id] = total[id << 1] + total[id << 1 | 1];
    }
}

inline void pushDown(const int& id, const int& l, const int& r) {
    if(l == r) return;
    if(!tag[id]) return;
    int mid = (l + r) >> 1;
    tag[id << 1] += tag[id];
    tag[id << 1 | 1] += tag[id];
    total[id << 1] += tag[id] * (mid - l + 1);
    total[id << 1 | 1] += tag[id] * (r - mid + 1);
    tag[id] = 0;
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

inline long long enquiry(const int& id, const int& l, const int& r, const int& borderL, const int& borderR) {
    if(l > borderL || r < borderR) return 0;
    if(l >= borderL && r <= borderR) return total[id];
    pushDown(id, l, r);
    int mid = (l + r) >> 1;
    return enquiry(id << 1, l, mid, borderL, borderR) + enquiry(id << 1 | 1, mid + 1, r, borderL, borderR);
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
                update(1, 1, N, x, y, k);
                break;
            case 2:
                cin >> x >> y;
                cout << enquiry(1, 1, N, x, y) << endl;
                break;
        }
    }
    return 0;
}