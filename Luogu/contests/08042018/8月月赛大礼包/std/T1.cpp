// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}
const int N=10000010,M=2010,MOD=998244353;
int a[N],C[M][M];
void getC(){
    C[0][0]=1;
    for (int i=1;i<M;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if (C[i][j]>=MOD) C[i][j]-=MOD;
        }
    }
}
int main(){
    getC();
    int n=read();
    for (int i=1;i<=n;++i) a[i]=read();
    int Q=read();
    while (Q--){
        int x=read(),y=read();
        int ans=0;
        for (int i=0,j=y;i<=x;++i){
            ans+=1ll*C[x][i]*a[j]%MOD;
            if (ans>=MOD) ans-=MOD;
            ++j;
            if (j>n) j=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}