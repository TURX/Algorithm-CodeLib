#include <cstdio>
#include <cstring>
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
        total[id] = total[id << 1] + total[id << 1 | 1]; // Add 2 children's values to the father (#this) node.
    }
}

inline void pushDown(const int& id, const int& currentIntervalL, const int& currentIntervalR) {
    //if(currentIntervalL == currentIntervalR) return;
    if(!tag[id]) return;
    tag[lson(id)] += tag[id];
    tag[rson(id)] += tag[id];
    int mid = (currentIntervalL + currentIntervalR) >> 1;
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
    int mid = (currentIntervalL + currentIntervalR) >> 1;
    update(lson(id), l, r, currentIntervalL, mid, val);
    update(rson(id), l, r, mid + 1, currentIntervalR, val);
    total[id] = total[lson(id)] + total[rson(id)];
}

long long enquiry(const int& id, const int& l, const int& r, const int& borderL, const int& borderR) {
    if(l > borderR || r < borderL) return 0;
    if(l <= borderL && r >= borderR) return total[id];
    // Initial: borderL = 1, borderR = N, l = x, r = y;
    long long ans = 0;
    pushDown(id, borderL, borderR);
    int mid = (borderL + borderR) >> 1;
    ans += enquiry(lson(id), l, r, borderL, mid);
    ans += enquiry(rson(id), l, r, mid + 1, borderR);
    return ans;
}

int main() {
    int T, N;
    char op[5], tmpC;
    scanf("%d", &T);
    for(int caseNum = 1; caseNum <= T; caseNum++) {
        printf("Case %d:\n", caseNum);
        scanf("%d", &N);
        for(int t = 1; t <= N; t++) scanf("%lld", &input[t]);
        preProcess(1, 1, N);
        while(true) {
            scanf("%s", op);
            if(!strcmp(op, "End")) break;
            if(!strcmp(op, "Add")) {
                int i; long long j;
                scanf("%d %lld", &i, &j);
                update(1, i, i, 1, N, j);
            }
            if(!strcmp(op, "Sub")) {
                int i; long long j;
                scanf("%d %lld", &i, &j);
                update(1, i, i, 1, N, -j);
            }
            if(!strcmp(op, "Query")) {
                getchar();
                getchar();
                int i; int j;
                scanf("%d %d", &i, &j);
                printf("%lld\n", enquiry(1, i, j, 1, N));
            }
        }
    }
    return 0;
}