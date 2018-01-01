#include<cstdio>
#include<cstring>
int min(int a,int b)
{
    return a > b ? b:a;     // 三目运算符，相当于if(a>b) return b; else return a;
}
int f[101][101];
int s[101];
int n,i,j,k,x;
int main()
{
    scanf("%d",&n);
    for (i=1; i<=n; i++) 
    {
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }
memset(f,127/3,sizeof(f));        //赋值127是很大的正数，若无/3后面的相加
    for (i=1; i<=n; i++) f[i][i]=0;   //可能超出int的范围
    for (i=n-1; i>=1; i--)
        for (j=i+1; j<=n; j++)
            for (k=i; k<=j-1; k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
    printf("%d\n",f[1][n]);
    return 0;
}
