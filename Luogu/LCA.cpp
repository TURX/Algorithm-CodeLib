#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 500000 + 2;
int n, m, s;
int k = 0;
int head[maxn], d[maxn], p[maxn][21]; //head数组就是链接表标配了吧？d存的是深度（deep）,p[i][j]存的[i]向上走2的j次方那么长的路径
struct node
{
    int v, next;
} e[maxn * 2]; //存树
void add(int u, int v)
{
    e[k].v = v;
    e[k].next = head[u];
    head[u] = k++;
} //加边函数
void dfs(int u, int fa)
{
    d[u] = d[fa] + 1;
    p[u][0] = fa;
    for (int i = 1; (1 << i) <= d[u]; i++)
        p[u][i] = p[p[u][i - 1]][i - 1];
    for (int i = head[u]; i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (v != fa)
            dfs(v, u);
    }
} //首先进行的预处理，将所有点的deep和p的初始值dfs出来
int lca(int a, int b) //非常标准的lca查找
{
    if (d[a] > d[b])
        swap(a, b); //保证a是在b结点上方，即a的深度小于b的深度
    for (int i = 20; i >= 0; i--)
        if (d[a] <= d[b] - (1 << i))
            b = p[b][i]; //先把b移到和a同一个深度
    if (a == b)
        return a; //特判，如果b上来和就和a一样了，那就可以直接返回答案了
    for (int i = 20; i >= 0; i--)
    {
        if (p[a][i] == p[b][i])
            continue;
        else
            a = p[a][i], b = p[b][i]; //A和B一起上移
    }
    return p[a][0]; //找出最后a值的数字
}
int main()
{
    memset(head, -1, sizeof(head));
    int a, b;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a); //无向图，要加两次
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}