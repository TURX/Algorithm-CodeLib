// https://www.luogu.org/blog/user50748/solution-p3366

#include<cstdio>
#include<algorithm>
using namespace std; 
struct note
{
    int start;
    int end;
    int time;    
};
int cmp(const note &a,const note &b)
{ 
    if(a.time<b.time)
        return 1;
    return 0;
}
int f[5001],n,m,k,s,tt,sum[5001];
struct note x[200001];
int getf(int v)
{
    if(f[v]==v)
        return v;
    else
    {
        f[v]=getf(f[v]);
        return f[v];
    }
}
void merge(int v,int u)
{
    int t1,t2;
    t1=getf(v);
    t2=getf(u);
    if(t1!=t2)
    {
        f[t2]=t1;
        sum[t1]=sum[t2]+sum[t1];
        tt=tt+s;
    }
    return;
}
int main()
{
    int i,flag=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        f[i]=i,sum[i]=1;
    for(i=1;i<=m;i++)
        scanf("%d %d %d",&x[i].start,&x[i].end,&x[i].time);
    sort(x+1,x+1+m,cmp);
    for(i=1;i<=m;i++)
    {
        s=x[i].time;
        merge(x[i].start,x[i].end);
        if(sum[getf(x[i].start)]==n)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("%d",tt);
    else
        printf("orz");
    return 0;
}