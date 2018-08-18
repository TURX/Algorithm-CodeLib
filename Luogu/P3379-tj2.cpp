#include<iostream>
#include<cstdio>
using namespace std;
struct Node{
    int dest, next;
}nodes[2*500001];
int depth[500001],fa[500001][22],lg[500001],head[500001];
int nodeCnt;
void add(int x,int y) //邻接表存树
{
    nodes[++nodeCnt].dest=y; 
    nodes[nodeCnt].next=head[x];
    head[x]=nodeCnt;
}
void dfs(const int& current, const int& fath)
{
    depth[current]=depth[fath]+1;
    fa[current][0]=fath;
    for(int i=1;(1<<i)<=depth[current];i++)
      fa[current][i]=fa[fa[current][i-1]][i-1];
    for(int i=head[current];i;i=nodes[i].next)
      if(nodes[i].dest!=fath)
        dfs(nodes[i].dest,current);
}
int lca(int& x, int& y)
{
    if(depth[x]<depth[y])
      swap(x,y);
    while(depth[x]>depth[y])
      x=fa[x][lg[depth[x]-depth[y]]-1];
    if(x==y)
      return x;
    for(int k=lg[depth[x]];k>=0;k--)
      if(fa[x][k]!=fa[y][k])
        x=fa[x][k], y=fa[y][k];
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