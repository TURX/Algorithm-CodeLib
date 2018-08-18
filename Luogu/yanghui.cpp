#include <cstdio>
int main()
{
int a[11][11]; //打印10行
int i,j; //用i来控制行数,j来控制列数
for(i=1;i<11;i++) //对第一列和对角线赋值为1
{
a[i][1]=1;
a[i][i]=1;
}
for(i=1;i<11;i++)
for(j=2;j<i;j++)
a[i][j]=a[i-1][j-1]+a[i-1][j];//杨辉三角的关系
for(i=1;i<11;i++)
{
for(j=1;j<=i;j++) //第n列有n个数
printf("%d ",a[i][j]);
printf("\n");
}
}