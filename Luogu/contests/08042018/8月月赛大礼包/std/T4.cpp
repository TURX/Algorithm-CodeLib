#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define maxn 200010
typedef long long LL;
LL b[maxn],ib[maxn],fac[maxn],ifac[maxn];
LL Pow(LL a,LL b)
{
    LL v=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)v=v*a%mod;
    return v;
}
LL C(int n,int m)
{
    return fac[m]*ifac[n]%mod*ifac[m-n]%mod;
}
LL A(int n,int m)
{
    return fac[m]*ifac[m-n]%mod;
}
int n,m;
int main()
{
    scanf("%d%d",&n,&m);int _=2*m+5;
    b[0]=1;fac[0]=1;
    for(int i=1;i<=_;i++)b[i]=b[i-1]*2%mod;
    for(int i=1;i<=_;i++)fac[i]=fac[i-1]*i%mod;
    for(int i=0;i<=_;i++)ib[i]=Pow(b[i],mod-2);
    for(int i=0;i<=_;i++)ifac[i]=Pow(fac[i],mod-2);
    LL ans=0;
    for(int i=0;i<=n;i++)
    {
        LL X=C(i,n)%mod*A(i,m)%mod*((i&1)?-1:1),Y=0;
        int k=min(n-i,m-n);
        for(int j=0;j<=k;j++)
            Y=(Y+fac[2*n-2*i]*C(n-i-j,m-i)%mod*C(2*j,m-n+j)%mod*ib[n-i-j]%mod)%mod;
    //	printf("%lld %lld\n",X,Y);
        ans=(ans+X*Y%mod)%mod;
    }
    printf("%lld",(ans*ib[n]%mod+mod)%mod);
}