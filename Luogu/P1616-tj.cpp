#include<cstdio>
#define sr c=getchar()  
#define input read()  
#define pd (c<'0'||c>'9')  
#define fk f=f*10+c-48  
#define ps if (c=='-') d=-1  
using namespace std;int f[10000001],w,c,m,n;//这个f真的大
int max(int x,int y)//最大值不解释
{
    return x>y?x:y;
}
int read()//输入流不解释
{
    char c;int d=1,f=0;
    while (sr,pd) ps; fk;
    while (sr,!pd) fk;
    return d*f;
}
void write(int x)//输出流不解释
{
    if (!x) return;
    write(x/10);
    putchar(x%10+48);
}
int main()
{
    m=input;n=input;
    for (int i=1;i<=n;i++)
    {
        w=input;c=input;//输入时间和价值
        for (int j=w;j<=m;j++)//完全背包
         f[j]=max(f[j],f[j-w]+c);
    }
    write(f[m]);
}