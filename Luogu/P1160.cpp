#include <iostream>
using namespace std;

bool p;
int N, M, k, root, tot = 2, pos;
struct Students {
    int l, r;
} stu[100001];

inline void insert(const int& val, const int& k, const bool& p) {
    switch(p) {
        case 0:
            stu[tot].r = k;
            stu[tot].l = stu[k].l;
            stu[k].l = tot;
            break;
        case 1:
            stu[tot].l = k;
            stu[tot].r = stu[k].r;
            stu[k].r = tot;
            break;
    }
    tot++;
}

inline int findRoot(const int& start) {
    if(stu[start].l) return findRoot(stu[start].l);
    return start;
}

inline void remove(const int& pos) {
    stu[stu[pos].l].r = stu[pos].r;
    stu[stu[pos].r].l = stu[pos].l;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    stu[1] = {0, 0};
    for(int t = 2; t <= N; t++) {
        cin >> k >> p;
        insert(t, k, p);
    }
    cin >> M;
    for(int t = 1; t <= M; t++) {
        cin >> k;
        remove(k);
    }
    pos = findRoot(1);
    while(stu[pos].r) {
        cout << stu[pos].r << ' ';
        pos = stu[pos].r;
    }
    return 0;
}