#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if (a==0)
    {
        x=0;y=1;
        d=b;
    }
    else
    {
        LL tx,ty;
        exgcd(b%a,a,d,tx,ty);
        x=ty-(b/a)*tx;
        y=tx;
    }
}
int main()
{
    LL a,b,d,x,y,b1,b2,m1,m2,A,B,K;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        bool u=true;
        scanf("%lld%lld",&m1,&b1);
        for (int i=2;i<=n;i++)
        {
            scanf("%lld%lld",&m2,&b2);
            A=m1;B=m2;K=b2-b1;
            exgcd(A,B,d,x,y);
            if (K%d!=0) u=false;
            x=((x*(K/d)%(B/d))+(B/d))%(B/d);
            b1=x*m1+b1;
            m1=m1*m2/d;
        }
        if (u==false) printf("-1\n");
        else printf("%lld\n",b1);
    }

    return 0;
}