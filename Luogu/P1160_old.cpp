#include <iostream>
using namespace std;

bool p;
int N, M, k, root, tot = 1, pos;
struct Students {
    int l = -1, r = -1, val;
} stu[100001];

inline void insert(const int& val, const int& k, const bool& p) {
    switch(p) {
        case 0:
            stu[tot].val = val;
            stu[tot].r = k;
            stu[tot].l = stu[k].l;
            stu[k].l = tot;
            break;
        case 1:
            stu[tot].val = val;
            stu[tot].l = k;
            stu[tot].r = stu[k].r;
            stu[k].r = tot;
            break;
    }
    tot++;
}

inline int search(const int& start, const int& val) {
    if(stu[start].val != val) {
        if(stu[start].r == -1) return -1;
        return search(stu[start].r, val);
    }
    return start;
}

inline int findRoot(const int& start) {
    if(stu[start].l != -1) return findRoot(stu[start].l);
    return start;
}

inline void remove(const int& pos) {
    if(pos == root) root = stu[pos].r;
    stu[stu[pos].l].r = stu[pos].r;
    stu[stu[pos].r].l = stu[pos].l;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    stu[0] = {-1, -1, 1};
    for(int t = 2; t <= N; t++) {
        cin >> k >> p;
        insert(t, k, p);
    }
    root = findRoot(1);
    cin >> M;
    for(int t = 1; t <= M; t++) {
        cin >> k;
        pos = search(root, k);
        if(pos != -1) remove(pos);
    }
    pos = root;
    while(pos != -1) {
        cout << stu[pos].val << ' ';
        pos = stu[pos].r;
    }
    return 0;
}