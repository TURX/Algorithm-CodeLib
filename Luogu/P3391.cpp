/*
 * Splay Tree   伸展树
 * Copyright by (C) 2019 TURX
 * 
 * Osusume Shiryou: https://tiger0132.blog.luogu.org/slay-notes
 */

#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 100001

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
     * rev      翻转标记（相当于线段树的懒标记）
     */
    int lson, rson, val, cnt, fa, size;
    bool rev;
};
SplayData splayTree[MAXN];

inline void buildTree(const int& N);
inline void reverse(const int& l, const int& r);
inline void output(const int& id);

int main() {
    scanf("%d%d", &N, &M);
    buildTree(N); // 建树
    while(M--) {
        scanf("%d%d", &l, &r);
        reverse(l, r); // 翻转l~r区间
    }
    output(root); // 从根开始输出解
    return 0;
}

// Main interior functions of Splay
inline bool checkIfRight(const int& id);
inline void updateCurrentSize(const int& id);

inline void rotate(const int& id) {
    /* Figure
          1S                      2
         /  \                    / \
        2R   3         ==>      4   1
       / \                         / \
      4   5                       5   3
      id:                   2
      singF:                1
      doubF:                0
      orientation:          false
      rson:                 5
    */

    int singF = splayTree[id].fa, doubF = splayTree[singF].fa; // fathers on single / double layer(s) above current
    bool orientation = checkIfRight(id); // orientation represents if i am the right child of my father
    int rson = splayTree[id].rson; // update the right son of my right son

    orientation ? splayTree[singF].rson = rson : splayTree[singF].lson = rson; // operations for rson to connect with singF
    splayTree[rson].fa = singF;

    checkIfRight(singF) ? splayTree[doubF].rson = id : splayTree[doubF].lson = id; // operations for me to connect with doubF
    splayTree[id].fa = doubF;
    
    orientation ? splayTree[id].lson = singF : splayTree[id].rson = singF; // operations for singF to connect with me
    splayTree[singF].fa = id;

    updateCurrentSize(singF), updateCurrentSize(id); // sizes of singF and me have been changed
}

inline void splay(const int& id, const int& dest = 0) { // Destination
    /* Figure 1
          1                       2
         /  \                    / \
        2R   3         ==>      4   1
       / \                         / \
      4   5                       5   3
      splayTree[id]:        2
      singF:                1
      doubF:                0
    */
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

// Auxiliary functions of Splay
inline bool checkIfRight(const int& id) {
    return splayTree[splayTree[id].fa].rson == id;
}

inline void updateCurrentSize(const int& id) { // It has an alias as pushUp() function, which updates the count of the total number of values in trees belonging to it
    splayTree[id].size = splayTree[splayTree[id].lson].size + splayTree[splayTree[id].rson].size + splayTree[id].cnt;
}

inline void find(const int& id) { // This helps splay() to rotate the maximized number which less or equal than x to the root
    if(!root) return; // No root, which means root = 0
    int current = root;
    while((id > splayTree[current].val ? splayTree[current].rson : splayTree[current].lson) && (id != splayTree[current].val)) {
        current = (id > splayTree[current].val ? splayTree[current].rson : splayTree[current].lson);
    }
    splay(current);
}

// Auxiliary modificating functions of Splay

inline void pushDown(const int& id) {
    if(!splayTree[id].rev) return;
    swap(splayTree[id].lson, splayTree[id].rson);
    splayTree[splayTree[id].lson].rev ^= 1; // Transport the reversing tag to sons from the father node
    splayTree[splayTree[id].rson].rev ^= 1;
    splayTree[id].rev = 0; // Clear the transported tag
}

inline int getValByRank(int rank) {
    int current = root;
    while(true) {
        pushDown(current);
        if(splayTree[current].lson && rank <= splayTree[splayTree[current].lson].size) {
            current = splayTree[current].lson;
        } else if(rank > splayTree[splayTree[current].lson].size + splayTree[current].cnt) {
            rank -= splayTree[splayTree[current].lson].size + splayTree[current].cnt;
            current = splayTree[current].rson;
        } else {
            return current;
        }
    }
}

inline void reverse(const int& l, const int& r) {
    int x = getValByRank(l), y = getValByRank(r + 2);
    splay(x); splay(y, x);
    splayTree[splayTree[y].lson].rev ^= 1;
}

// Main exterior functions
inline void buildTree(const int& N) {
    /*
     * Why 0 and N + 1 exist there?
     * Because the Splay tree needs 2 nodes to maintain its BST shape (like -INF and INF in Treap).
     */
    for(register int t = 0; t <= N + 1; t++) insert(t);
}

inline void output(const int& id) {
    pushDown(id);
    if(splayTree[id].lson) output(splayTree[id].lson);
    if(splayTree[id].val && splayTree[id].val <= N) printf("%d ", splayTree[id].val);
    if(splayTree[id].rson) output(splayTree[id].rson);
}