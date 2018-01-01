#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    if(x<=150)
      printf("%.1f",x*0.4463);
    else
        if((x>=151)&&(x<=400))
          printf("%.1f",150*0.4463+(x-150)*0.4663); 
        else
            printf("%.1f",150*0.4463+250*0.4663+(x-400)*0.5663);
    return 0;
}
