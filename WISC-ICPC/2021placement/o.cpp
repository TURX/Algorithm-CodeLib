#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
const int MAXN=1e5+5;
using namespace std;
 
char a[MAXN];
char b[MAXN];
int main()
{
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    int len=strlen(a);
    int l,r;
    for(int i=0;i<len;i++){
        if(a[i]!=b[i]){           //左边不同的下标
            l=i;
            break;
        }
    }
    for(int i=len-1;i>=0;i--){     //右边不同的下标
        if(a[i]!=b[i]){
            r=i;
            break;
        }
    }
    for(int i=l,j=r;i<=r;i++,j--){   //判断是否可以旋转得到目标
        if(a[i]!=b[j]){
            printf("0\n");
            return 0;
        }
    }
   int cnt=1;                        //确认可以赋值为1
   l--;
   r++;
   while(l>=0&&r<len&&a[l]==a[r]){    //往两端继续寻找相同的字符扩展长度
    l--;
    r++;
    cnt++;
   }
   printf("%d\n",cnt);
   return 0;
}