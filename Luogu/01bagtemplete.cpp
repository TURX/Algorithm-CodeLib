#include <stdio.h>  
#define N 1050017
int wei[N],val[N],f[N];  
int main()  
{  
    int i, j, n, m;  
    while(scanf("%d",&n)!=EOF)  
    {  
        scanf("%d", &m);  
        for(i=0; i<n; i++)  
            scanf("%d%d", &wei[i],&val[i]);//wei[i]Ϊ������val[i]Ϊ��ֵ  
        for(i=0; i<n; i++)  
        {  
            for(j=m; j>=wei[i]; j--)  
                f[j] = max(f[j], f[j-wei[i]]+val[i]);  
        }  
        printf("%d\n",f[m]);  
    }  
    return 0;  
}
