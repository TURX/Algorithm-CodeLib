#include<stdio.h>
int b[10000];
int main(){
    int i,le,m,l,r,to,j;
    scanf("%d%d",&le,&m);
    to=le+1;
    for(i=1;i<=m;i++){
        scanf("%d%d",&l,&r);
        for(j=l;j<=r;j++)
            b[j]=1;
    }
    for(i=0;i<=le;i++)
        if(b[i])to--;
    printf("%d",to);
    return 0;
}
