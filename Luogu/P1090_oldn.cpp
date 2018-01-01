#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int,vector<int>,greater<int>> queue;
	
	return 0;
}
/*
优先队列+读入优化

个人认为是比较快的（据说手写优先队列会更快，但是我很bu懒hui，所以就不写了）

以下是代码。楼下几位神犇已经讲的很清楚了，我也只是贴个代码，骗点积分而已

#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;  //定义一个名为q的优先队列
inline int read() //拙劣的快读（据说还有更快的）。
{
    int ff=1,ee=0;
    char ss=getchar();
    while ((ss<'0'||ss>'9')&&ss!='-') ss=getchar();
    while ((ss>='0'&&ss<='9')||ss=='-') {
        if (ss=='-') ff=-1;
        else ee=ee*10+ss-'0';
        ss=getchar();
    }
    return ee*ff;
}
int main ()
{
    int n=read(),ans=0;
    for (int i=1;i<=n;i++)
    q.push(read());//读入不解释
    for (int i=1;i<=n-1;i++)
    {
        int a=q.top();//贪心，取两次最小的元素，加起来再塞回去，直到只剩下一个元素为止
        q.pop();
        int b=q.top();
        q.pop();
        q.push(a+b);
        ans+=a+b;
    }
    printf ("%d",ans);
    return 0;
}
*/