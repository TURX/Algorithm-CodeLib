// https://blog.csdn.net/MIKASA3/article/details/51338332

#include <iostream>
#include <stdio.h>
#include <algorithm>
const int maxn = 100005;
using namespace std;
int sor[maxn]; //借助sort排序的数组
struct node
{
    int num[maxn]; //当前层的数
    int cnt[maxn]; //核心部分，保存每一个元素的左边的元素中位于下一层左子树的个数
} tree[40];        //40是树的层数
//建树代码如下
void buildtree(int l, int r, int d) //d是深度
{
    if (l == r)
        return;                        //递归出口
    int mid = (l + r) >> 1;            //划分左右区间
    int opleft = l, opright = mid + 1; //对左右子树的操作位置的初始化
    int same_as_mid = 0;               //和sor[mid]相同的数的数目
    //计算在mid左边有多少个和sor[mid]相同的数（包括mid）,都要放到左子树
    for (int i = mid; i > 0; i--)
    {
        if (sor[i] == sor[mid])
            same_as_mid++;
        else
            break;
    }
    int cnt_left = 0; //被划分到左子树的个数
    for (int i = l; i <= r; i++)
    {
        //从l到r开始遍历
        if (tree[d].num[i] < sor[mid]) //左
        {
            tree[d + 1].num[opleft++] = tree[d].num[i];
            cnt_left++;
            tree[d].cnt[i] = cnt_left;
        }
        else if (tree[d].num[i] == sor[mid] && same_as_mid)
        {
            //相同的都放在左子树
            tree[d + 1].num[opleft++] = tree[d].num[i];
            cnt_left++;
            tree[d].cnt[i] = cnt_left;
            same_as_mid--;
        }
        else //右
        {
            tree[d].cnt[i] = cnt_left;
            tree[d + 1].num[opright++] = tree[d].num[i];
        }
    }
    buildtree(l, mid, d + 1); //递归建树
    buildtree(mid + 1, r, d + 1);
}
int query(int l, int r, int d, int ql, int qr, int k) //在d层[l,r]的节点里查找[a,b]中的第k小值
{
    if (l == r)
        return tree[d].num[l]; //递归出口
    int mid = (l + r) >> 1;
    int sum_in_left; //区间内元素位于下一层左子树的个数
    int left;        //[l,ql-1]左边的元素中位于下一层左子树的个数
    if (ql == l)
    {
        //如果ql是节点的左边界则有cnt[qr]个数进入左子树
        sum_in_left = tree[d].cnt[qr];
        left = 0;
    }
    else
    {
        //如果ql不是节点的左边界则有cnt[qr]-cnt[ql-1]个数进入了左子树
        sum_in_left = tree[d].cnt[qr] - tree[d].cnt[ql - 1];
        left = tree[d].cnt[ql - 1];
    }
    if (sum_in_left >= k)
    {
        //要找的点在左子树
        //确定下一步询问的位置：
        //如果在ql的左边有left个进入左子树
        //那么ql到qr中第一个进入左子树的必定在l+left的位置
        int new_ql = l + left;
        int new_qr = new_ql + sum_in_left - 1;
        return query(l, mid, d + 1, new_ql, new_qr, k);
    }
    else //要找的点在右子树
    {
        //确定下一步询问的位置
        int a = ql - l - left;             //表示当前区间左半部分即[l,ql-1]中在下一层是右孩子的个数
        int b = qr - ql + 1 - sum_in_left; //表示当前区间右半部分即[ql,qr]中在下一层是右孩子的个数
        int new_ql = mid + a + 1;
        int new_qr = mid + a + b;
        //k-sum_in_left表示要减去区间里已经进入左子树的个数
        return query(mid + 1, r, d + 1, new_ql, new_qr, k - sum_in_left);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N, Len, ans = 0;
    cin >> N >> Len;
    for(int i = 1; i <= N; ++i) {
        cin >> sor[i];
        tree[0].num[i] = sor[i];
    }
    sort(sor + 1, sor + N + 1);
    buildtree(1, N, 0);
    for(int i = 1; i <= N; i++) {
        for(int j = i + Len - 1; j <= N; j++) {
            int k = (j - i) / 2 + 1;
            ans = max(ans, query(1, N, 0, i, j, k));
        }
    }
    cout << ans << endl;
    return 0;
}