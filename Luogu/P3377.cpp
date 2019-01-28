#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100001
int op, x, y, N, M, input, root;

struct LeftistUtil { // 封装
    struct LeftistBasic {
        /*
         * val: 当前节点的值
         * dist：当前节点到最近的叶节点的距离
         * lson: 当前节点的左节点的下标
         * rson: 当前节点的右节点的下标
         * fa：当前节点的父亲
         */
        int val, dist, lson, rson, fa;
    } leftistData[MAXN];

    int merge(int x, int y) {
        if(!x | !y) return x + y; // x和y中有一个为0，即无法再合并下去  为什么返回x + y？
        if(leftistData[x].val > leftistData[y].val || (leftistData[x].val == leftistData[y].val) && x > y) swap(x, y); // 小根堆基本性质：根要比儿子小，所以x要是x和y中值较小的一个
        leftistData[x].rson = merge(leftistData[x].rson, y); // 为什么？
        // leftistData[leftistData[x].rson].fa = x; // 右儿子的父亲显然是自己
        if(leftistData[leftistData[x].lson].dist < leftistData[leftistData[x].rson].dist) swap(leftistData[x].lson, leftistData[x].rson); // 左偏树基本性质：左儿子到最近叶子节点的距离小于右儿子到最近叶子节点的距离
        leftistData[leftistData[x].lson].fa = leftistData[leftistData[x].rson].fa = leftistData[x].fa = x;
        leftistData[x].dist = leftistData[leftistData[x].rson].dist + 1; // 右子树经过交换，一定是处于距离最小化的状态，所以当前节点的距离（x.dist）就是当前节点的右节点（最小距叶节点的距离）加一（到当前节点的增加消耗）
        return x; // 一般情况下返回x，即使用当前节点作为父亲的右儿子进行合并    为什么？
    }

    void pop(int x) { // 删除最顶端的值（最值）的方法即为合并根的左右儿子
        leftistData[x].val = -1;
        leftistData[leftistData[x].lson].fa = leftistData[x].lson;
        leftistData[leftistData[x].rson].fa = leftistData[x].rson;
        leftistData[x].fa = merge(leftistData[x].lson, leftistData[x].rson);
    }

    int getFather(int x) { // 类似于并查集，递归找根
        return leftistData[x].fa == x ? x : leftistData[x].fa = getFather(leftistData[x].fa);
    }
} U;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    U.leftistData[0].dist = -1;
    for(int t = 1; t <= N; t++) {
        cin >> input;
        U.leftistData[t].fa = t;
        U.leftistData[t].val = input;
    }
    while(M--) {
        cin >> op;
        switch(op) { // 操作1：将第x个数和第y个数所在的小根堆合并
            case 1: 
                cin >> x >> y;
                if (U.leftistData[x].val == -1 || U.leftistData[y].val == -1) continue;
                x = U.getFather(x), y = U.getFather(y);
                if(x != y) U.leftistData[x].fa = U.leftistData[y].fa = U.merge(U.getFather(x), U.getFather(y));
                break;
            case 2: // 操作2；输出第x个数所在的堆的最小数
                cin >> x;
                if(U.leftistData[x].val == -1) {
                    cout << "-1" << endl;
                    break;
                }
                x = U.getFather(x);
                cout << U.leftistData[x].val << endl; // 左偏树的最值在根上，因为还是满足小根堆的性质
                if(U.leftistData[x].val != -1) U.pop(x);
                break;
        }
    }
    return 0;
}