// 平衡树 Treap
// Copyright by (C) TURX & lydrainbowcat

#include <iostream>
using namespace std;

#define SIZE 100010
#define INF 0x7fffffff

struct Treap {
    int l, r; // 左、右儿子
    int val, dat; // 节点关键码（随机数维护平衡性）、权值
    int cnt, size; // 副本数，子树大小
} a[SIZE]; // 数组模拟链表
int root = 1, tot, n;

int New(int val) { // 新增节点
    a[++tot].val = val; // 真实值
    a[tot].dat = rand(); // 类似于二叉堆，使用随机数进行平衡性维护（我们在这里把它称为维护值）
    a[tot].cnt = a[tot].size = 1; // 叶节点
    return tot; // 返回此时平衡树上的节点数
}

void Update(int p) {
    a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt; // 和线段树pushDown类似，即自己的子树大小=左儿子子树大小+右儿子子树大小+自己的副本数
}

void Build() { // 建立平衡树
    New(-INF), New(INF); // 建立两个节点作为基本的BST结构
    a[1].r = 2; // 设置根节点（默认为1），并确认前面建立的两个节点的关系（即-INF的右儿子为INF，且根为-INF）
    Update(root); // 更新根的大小
}

int GetRankByVal(int p, int val) { // 题中查询k数的排名
    if(p == 0) return 0; // 0代表没有子树，因为传的值是儿子，可以看下面的调用
    if(val == a[p].val) return a[a[p].l].size + 1; // 如果当前节点值是查询值的话，就可以直接返回，即查询节点排名=当前节点排名=左子树大小+当前节点
    if(val < a[p].val) return GetRankByVal(a[p].l, val); // 如果当前节点值比查询值大，即查询节点在当前节点的左子树中，所以递归进入左子树查找
    return GetRankByVal(a[p].r, val) + a[a[p].l].size + a[p].cnt; // 相当于else，即查询节点在当前节点的右子树中，所以递归进入右子树查找；但是右子树只能查找出右边的部分值，所以还要加上一些，即查询节点排名=左子树大小+当前节点的副本数+递归查找右子树的结果
}

int GetValByRank(int p, int rank) { // 题中查询排名为x的数
    if(p == 0) return INF; // 0代表没有子树，因为传的值是儿子，可以看下面的调用
    if(a[a[p].l].size >= rank) return GetValByRank(a[p].l, rank); // 如果当前节点子树大小比查询值大或等于查询值，即当前节点排名一定大于或等于查询值，所以递归进入左子树查找
    if(a[a[p].l].size + a[p].cnt >= rank) return a[p].val; // 如果当前节点子树大小+当前节点的副本数，即当前节点的局部排名，如果大于或等于查询值，即被查询到，就返回值
    return GetValByRank(a[p].r, rank - a[a[p].l].size - a[p].cnt); // 相当于else，即查询节点不存在在当前节点和当前节点的左子树中，而且因为在右子树中查询节点的排名和总排名会相差当前节点的排名，即左子树的大小+当前节点的副本数，所以此时在右子树中使用局部排名递归查询并返回查询值
}

void zig(int& p) { // 右旋 - 在保持BST性质的基础上，可以理解为zig(p)把p的左儿子绕着p向右旋转
    /* 图示
           1 <= 旋转它                2
         /  \                       /  \
        2    3         ==>         4   1
       / \                            / \
      4  5                           5  3
    */
    int q = a[p].l; // 把左儿子变为当前节点
    a[p].l = a[q].r, a[q].r = p, p = q; // 把旧当前节点的左儿子变为当前节点的右儿子，把旧当前节点的右儿子变为当前节点
    Update(a[p].r), Update(p); // 更新当前和旧当前（即当前的右儿子）节点的大小
}

void zag(int& p) { // 左旋 - 在保持BST性质的基础上，可以理解为zag(p)把p的右儿子绕着p向左旋转
    /* 图示
        2                              1 
      /  \                           /  \
     4   1 <= 旋转它     ==>         2    3
        / \                       /  \
       5  3                      4   5
    */
    int q = a[p].r; // 把右儿子变为当前节点
    a[p].r = a[q].l, a[q].l = p, p = q; // 把旧当前节点的右儿子变为当前节点的左儿子，把旧当前节点的左儿子变为当前节点
    Update(a[p].l), Update(p); // 更新当前和旧当前（即当前的左儿子）节点的大小
}

void Insert(int& p, int val) { // 题中插入x数
    if(p == 0) { // 如果根为0（非法）
        p = New(val); // 直接插入值后重设根
        return;
    }
    if(val == a[p].val) { // 如果已存在当前插入值
        a[p].cnt++, Update(p); // 直接增加副本数并更新子树大小
        return;
    }
    if(val < a[p].val) { // 插入值小于当前值（BST性质）
        Insert(a[p].l, val); // 插入到左子树中
        if(a[p].dat < a[a[p].l].dat) zig(p); // 不满足堆性质，右旋
    }
    else { // else，即插入值大于或等于当前值（BST性质）
        Insert(a[p].r, val); // 插入到右子树中
        if(a[p].dat < a[a[p].r].dat) zag(p); // 不满足堆性质，左旋
    }
    Update(p); // 插入后更新子树大小
}   

int GetPre(int val) { // 题中求x的前驱，因为平衡树是BST，所以前驱为在左子树上一直向右走的终值
    int ans = 1; // a[1].val == INF，应对没有前驱的情况
    int p = root; // 不能修改原根
    while(p) { // 即现根不为0（合法）时
        if(val == a[p].val) { // 如果当前节点值等于查询参数，那么答案只会在当前节点的左子树内
            if(a[p].l > 0) { // 如果当前当前节点有左子树
                p = a[p].l; // 就定位到左子树上
                while(a[p].r > 0) p = a[p].r; // 左子树上一直向右走
                ans = p; // 答案即为最右边节点的值
            }
            break; // 成功查询，准备返回值
        } // 下面是没有左子树或当前节点值不等于查询参数，即需要调整节点的情况
        if(a[p].val < val && a[p].val > a[ans].val) ans = p; // 查询当前节点失败，特判两个条件：当前根的值比查询参数值小，即被修改过根；且当前根的值比答案大，即答案错误，即右子树上没有最大值；所以此处重置答案为最大的根节点
        p = val < a[p].val ? a[p].l : a[p].r; // 特判结束后，如果查询参数值比当前根的值小，就往左子树上搜，大于或等于则往右子树上搜，即调整节点
    }
    return a[ans].val; // 返回答案
}

int GetNext(int val) { // 题中求x的后继，因为平衡树是BST，所以前驱为在右子树上一直向左走的终值
    int ans = 2; // a[2].val == INF，应对没有后继的情况
    int p = root; // 不能修改原根
    while(p) { // 即现根不为0（合法）时
        if(val == a[p].val) { // 如果当前节点值等于查询参数，那么答案只会在当前节点的右子树内
            if(a[p].r > 0) { // 如果当前当前节点有右子树
                p = a[p].r; // 就定位到右子树上
                while(a[p].l > 0) p = a[p].l; // 右子树上一直向左走
                ans = p; // 答案即为最左边节点的值
            }
            break; // 成功查询，准备返回值
        } // 下面是没有右子树或当前节点值不等于查询参数，即需要调整现根的情况
        if(a[p].val > val && a[p].val < a[ans].val) ans = p; // 查询当前节点失败，特判两个条件：当前根的值比查询参数值大，即被修改过根；且当前根的值比答案小，即答案错误，即左子树上没有最大值；所以此处重置答案为最小的根节点
        p = val < a[p].val ? a[p].l : a[p].r; // 特判结束后，如果查询参数值比当前根的值小，就往左子树上搜，大于或等于则往右子树上搜，即调整现根
    }
    return a[ans].val; // 返回答案
}

void Remove(int& p, int val) { // 题中删除x数
    if(p == 0) return; // 检查根的合法性
    if(val == a[p].val) { // 检索到了val
        if(a[p].cnt > 1) { // 有重复，减少副本数即可
            a[p].cnt--, Update(p); // 减少副本数并更新子树大小
            return;
        }
        if(a[p].l || a[p].r) { // 不是叶子节点，一直递归向下旋转，成为叶子节点后删除
            if(a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat) { // 没有右子树或者达到平衡
                zig(p), Remove(a[p].r, val); // 右旋
            } else { // 有右子树且不平衡
                zag(p), Remove(a[p].l, val); // 左旋
            }
            Update(p); // 旋转后更新子树大小
        } else {
            p = 0; // 叶子节点，删除
        }
        return;
    }
    val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val); // 没有检索到val，即调整根，即如果查询参数值比当前根的值小，就往左子树上搜，大于或等于则往右子树上搜
    Update(p); // 删除后更新子树大小
}

int main() {
    Build(); // 建树
    cin >> n; // 输入操作的次数n
    while(n--) { // 每次操作
        int opt, x; // opt表示操作的序号，x表示执行参数
        cin >> opt >> x;
        switch(opt) {
            case 1:
                Insert(root, x);
                break;
            case 2:
                Remove(root, x);
                break;
            case 3:
                cout << GetRankByVal(root, x) - 1 << endl;
                break;
            case 4:
                cout << GetValByRank(root, x + 1) << endl;
                break;
            case 5:
                cout << GetPre(x) << endl;
                break;
            case 6:
                cout << GetNext(x) << endl;
                break;
        }
    }
    return 0;
}