#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    int x,y,val;
}e[15];
int m;
int c[350000];
int num[3];
int sum[5];
int temp[5];
int Slove(int mid)
{
    int cnt=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=i;j<=3;j++)
        {
            cnt++;
            e[cnt].x=i,e[cnt].y=j,e[cnt].val=sum[i]+sum[j];
        }
    }
    for(int i=1;i<=3;i++)temp[i]=num[i];
    for(int i=1;i<=m;i++)
    {
        int flag=0;
        for(int j=1;j<=cnt;j++)
        {
            if(temp[e[j].x]==0||temp[e[j].y]==0||e[j].val*c[i]<mid)continue;
            if(e[j].x==e[j].y&&temp[e[j].x]<2)continue;
            temp[e[j].x]--;temp[e[j].y]--;
            flag=1;
            break;
        }
        if(flag==0)return 0;
    }
    return 1;
}
int main()
{
    while(~scanf("%d%d%d",&num[1],&num[2],&num[3]))
    {
        m=num[1]+num[2]+num[3];
        for(int i=1;i<=3;i++)scanf("%d",&sum[i]);
        m/=2;
        for(int i=1;i<=m;i++)scanf("%d",&c[i]);
        sort(c+1,c+1+m);
        int l=0;
        int r=1000000000;
        int ans=0;
        while(r-l>=0)
        {
            int mid=(l+r)/2;
            if(Slove(mid)==1)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
}