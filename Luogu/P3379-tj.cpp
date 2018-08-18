#include<iostream>
#include<cstdio>
using namespace std;
struct Nodes{
    int dest, next;
} nodes[2*500001];
int depth[500001],fa[500001][22],lg[500001],head[500001];
int nodeCnt;
void add(int x,int y) //邻接表存树
{
    nodes[++nodeCnt] = {y, head[x]};
    head[x]=nodeCnt;
}
void dfs(const int& current, int father)
{
    depth[current]=depth[father]+1;
    fa[current][0]=father;
    for(int i=1;(1<<i)<=depth[current];i++)
      fa[current][i]=fa[fa[current][i-1]][i-1];
    for(int t = head[current]; t; t = nodes[t].next)
      if(nodes[t].dest != father) dfs(nodes[t].dest, current);
}
inline int lca(int x,int y)
{
    if(depth[x] < depth[y]) swap(x,y);
    while(depth[x] > depth[y])
      x = fa[x][lg[depth[x] - depth[y]] - 1];
    if(x == y) return x;
    for(int t = lg[depth[x]]; t >= 0; t--)
      if(fa[x][t] != fa[y][t]) {
        x=fa[x][t];
        y=fa[y][t];
      }
    return fa[x][0];
}
int n,m,s;
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;  scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    dfs(s,0);

    for(int i=1;i<=n;i++)
      lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=m;i++)
    {
        int x,y;  scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }

    return 0;
}