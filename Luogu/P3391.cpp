/*
 * Splay Tree   伸展树
 * Copyright by (C) 2019 TURX
 * 
 * Osusume Shiryou: https://tiger0132.blog.luogu.org/slay-notes
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * N        表示初始序列中数的个数
 * M        表示翻转操作的个数
 * l        临时区间的左侧
 * r        临时区间的右侧
 * root     根
 * totCnt   整棵储存的权值个数（包括重复权值）
 */
int N, M, l, r, root, totCnt;

struct SplayData {
    /*
     * lson     左儿子的下标
     * rson     右儿子的下标
     * val      值
     * cnt      存储的重复权值的个数
     * fa       父节点
     * size     子树储存的权值个数（包括重复权值）
     */
    int lson, rson, val, cnt, fa, size;
};
vector<SplayData> splayTree;

void buildTree(const int& N);
void reverse(const int& l, const int& r);

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    buildTree(N);
    while(M--) {
        cin >> l >> r;
        reverse(l, r);
    }
    return 0;
}

// Auxiliary functions of Splay
inline bool checkIfRight(const int& id) {
    return splayTree[splayTree[id].fa].rson == id;
}

inline void updateCurrentSize(const int& id) { // It has an alias as pushUp() function, which updates the count of the total number of values in trees belonging to it
    splayTree[id].size = splayTree[splayTree[id].lson].size + splayTree[splayTree[id].rson].size + splayTree[id].size;
}

inline void find(const int& id) { // This helps splay() to rotate the maximized number which less or equal than x to the root
    if(!root) return; // No root, which means root = 0
    int current = root;
    while((id > splayTree[current].val ? splayTree[current].rson : splayTree[current].lson) && (id != splayTree[current].val)) {
        current = (id > splayTree[current].val ? splayTree[current].rson : splayTree[current].lson);
    }
    splay(current);
}

// Main interior functions of Splay
inline void rotate(const int& id) {
    int singF = splayTree[id].fa, doubF = splayTree[singF].fa; // Fathers on single / double layer(s) above current
    bool orientation = checkIfRight(id);
    int rson = splayTree[id].rson;

    orientation ? splayTree[singF].rson = rson : splayTree[singF].lson = rson;
    splayTree[rson].fa = singF;
    checkIfRight(singF) ? splayTree[doubF].rson = id : splayTree[doubF].lson = id;
    splayTree[id].fa = doubF;
    orientation ? splayTree[id].rson = singF : splayTree[id].lson = singF;
    splayTree[singF].fa = id;
    updateCurrentSize(singF), updateCurrentSize(id);
}

inline void splay(const int& id, const int& dest = 0) { // Destination
    while(splayTree[id].fa != dest) {
        int singF = splayTree[id].fa, doubF = splayTree[singF].fa;
        if(doubF != dest) {
            if(checkIfRight(id) == checkIfRight(singF)) rotate(singF);
            else rotate(id);
        }
        rotate(id); // Rotate 2 times here
    }
    if(!dest) root = id;
}

inline void insert(const int& x) {
    int current = root, previous = 0;
    while(current && splayTree[current].val != x) {
        previous = current;
        current = (x > splayTree[current].val ? splayTree[current].rson : splayTree[current].lson);
    }
    if(current) splayTree[current].cnt++;
    else {
        current = ++totCnt;
        if(previous) (x > splayTree[previous].val ? splayTree[previous].rson : splayTree[previous].lson) = current;
        splayTree[current].lson = splayTree[current].rson = 0;
        splayTree[current].val = x;
        splayTree[current].fa = previous;
        splayTree[current].cnt = splayTree[current].size = 1;
    }
    splay(current);
}

// Main exterior functions
inline void buildTree(const int& N) {
    for(int t = 0; t <= N + 1; t++) insert(t);
}