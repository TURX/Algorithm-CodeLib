#include <iostream>
#include <string>
using namespace std;

#define lson(x) x << 1
#define rson(x) x << 1 | 1
#define mid(x, y) ((x + y) >> 1)
#define MAXN 100001

long long total[MAXN << 2], tag[MAXN << 2], input[MAXN];

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
    int mid = mid(currentIntervalL, currentIntervalR);
    tag[lson(id)] += tag[id];
    tag[rson(id)] += tag[id];
    total[lson(id)] += tag[id] * (mid - currentIntervalL + 1);
    total[rson(id)] += tag[id] * (currentIntervalR - mid);
    tag[id] = 0;
}

void update(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR, const long long& val) {
    if(l > currentIntervalR || r < currentIntervalL) return;
    if(l <= currentIntervalL && r >= currentIntervalR) {
        total[id] += val * (currentIntervalR - currentIntervalL + 1);
        tag[id] += val;
        return;
    }
    pushDown(id, currentIntervalL, currentIntervalR);
    int mid = mid(currentIntervalL, currentIntervalR);
    update(lson(id), l, r, currentIntervalL, mid, val);
    update(rson(id), l, r, mid + 1, currentIntervalR, val);
    total[id] = total[lson(id)] + total[rson(id)];
}

long long enquiry(const int& id, const int& l, const int& r, const int& currentIntervalL, const int& currentIntervalR) {
    if(l > currentIntervalR || r < currentIntervalL) return 0;
    if(l <= currentIntervalL && r >= currentIntervalR) return total[id];
    long long ans = 0;
    int mid = mid(currentIntervalL, currentIntervalR);
    ans += enquiry(lson(id), l, r, currentIntervalL, mid);
    ans += enquiry(rson(id), l, r, mid + 1, currentIntervalR);
    return ans;
}

int main() {
    int T, N;
    long long i, j;
    char opt[3], tmpC;
    cin >> T;
    for(int caseNum = 1; caseNum <= T; caseNum++) {
        cout << "Case " << caseNum << ":" << endl;
        cin >> N;
        for(int t = 1; t <= N; t++) cin >> input[t];
        preProcess(1, 1, N);
        while(true) {
            cin >> opt[0] >> opt[1] >> opt[2];
            string op;
            op.push_back(opt[0]); op.push_back(opt[1]); op.push_back(opt[2]);
            if(op == "End") break;
            if(op == "Add") {
                cin >> i >> j;
                update(1, i, i, 1, N, j);
            }
            if(op == "Sub") {
                cin >> i >> j;
                update(1, i, i, 1, N, -j);
            }
            if(op == "Que") {
                getchar();
                getchar();
                cin >> i >> j;
                cout << enquiry(1, i, j, 1, N) << endl;
            }
        }
    }
    return 0;
}