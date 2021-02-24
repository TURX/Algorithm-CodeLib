#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long n,m,a[1000001],ans[1000001<<2],tag[1000001<<2];
inline long long ls(long long x)
{
    return x<<1;
}
inline long long rs(long long x)
{
    return x<<1|1;
}
void scan()
{
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    scanf("%lld",&a[i]);
}
inline void push_up(long long p)
{
    ans[p]=ans[ls(p)]+ans[rs(p)];
}
void build(long long p,long long l,long long r)
{
    tag[p]=0;
    if(l==r){ans[p]=a[l];return ;}
    long long mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);
} 
inline void f(long long p,long long l,long long r,long long k)
{
    tag[p]=tag[p]+k;
    ans[p]=ans[p]+k*(r-l+1);
}
inline void push_down(long long p,long long l,long long r)
{
    long long mid=(l+r)>>1;
    f(ls(p),l,mid,tag[p]);
    f(rs(p),mid+1,r,tag[p]);
    tag[p]=0;
}
inline void update(long long nl,long long nr,long long l,long long r,long long p,long long k)
{
    if(nl<=l&&r<=nr)
    {
        ans[p]+=k*(r-l+1);
        tag[p]+=k;
        return ;
    }
    push_down(p,l,r);
    long long mid=(l+r)>>1;
    if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
    if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
    push_up(p);
}
long long query(long long q_x,long long q_y,long long l,long long r,long long p)
{
    long long res=0;
    if(q_x<=l&&r<=q_y)return ans[p];
    long long mid=(l+r)>>1;
    push_down(p,l,r);
    if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
    if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
    return res;
}
int main()
{
    long long a1,b,c,d,e,f;
    scan();
    build(1,1,n);
    while(m--)
    {
        scanf("%lld",&a1);
        switch(a1)
        {
            case 1:{
                scanf("%lld%lld%lld",&b,&c,&d);
                update(b,c,1,n,1,d);
                break;
            }
            case 2:{
                scanf("%lld%lld",&e,&f);
                printf("%lld\n",query(e,f,1,n,1));
                break;
            }
        }
    }
    return 0;
}