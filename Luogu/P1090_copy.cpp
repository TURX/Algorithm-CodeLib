#include<bits/stdc++.h>
#define r(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int a[10001],n,i,t,ans;
int main()
{
	//freopen("testdata.in","r",stdin); 260332759
    scanf("%d",&n);
    r(i,1,n)    scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    r(i,1,n-1)
    {
        a[i+1]+=a[i];
        ans+=a[i+1];
        t=i+1;
        while(t<n&&a[t]>a[t+1])
            swap(a[t],a[t+1]),t++;
    }
    printf("%d",ans);
return 0;
}
