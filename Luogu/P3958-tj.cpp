#include <iostream> //万能头，最好不要用
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;//不加爆零
int ufset[1001];//并查集
int find(int x){
    if (x!=ufset[x]) ufset[x]=find(ufset[x]);
    return ufset[x];
}//查找+路径压缩
double dist(long long x,long long y,long long z,long long x1,long long y1,long long z1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
}//两点距离公式
long long x[100001],y[100001],z[100001];
int touchTop[100001],touchBottom[100001];
vector<int> touchTop, touchBottom;
//touchTop记录与顶面相交的洞的序号
//touchBottom记录与底面相交的洞的序号
int main(){
    int t;
    scanf("%d",&t);
    int n,h; 
    long long r;
    for (int i=1;i<=t;i++){
        scanf("%d%d%ld",&n,&h,&r);//long long不开的话...
        int tot1=0;//记录与顶面相交的洞有几个
        int tot2=0;//记录与底面相交// 
        for (int j=1;j<=n;j++){
          ufset[j]=j;  //并查集初始// 
         }
        for (int j=1;j<=n;j++){
            scanf("%ld%ld%ld",&x[j], &y[j], &z[j]);// ong long不开的话...
            if (z[j]+r>=h){//判断这// 交
                tot1++;
                touchTop[tot1]=j;
            }
            if (z[j]-r<=0){//判断这// 交
                tot2++;
                touchBottom[tot2]=j;// 
            }
            for (int k=1;k<=j;k++){//枚举之前的洞是否与这个洞相交，如果相交则合并集合
                if (dist(x[j],y[j],z[j],x[k],y[k],z[k])<=2*r){
                    int a1=find(j);
                    int a2=find(k);
                    if (a1!=a2)
                      ufset[a1]=a2;
                }
            }
        }
        int s=0;
        //看看每一个中是否有洞连接上下面
        for (int j=1;j<=tot1;j++){
            for (int k=1;k<=tot2;k++){
                if (find(touchTop[j])==find(touchBottom[k])){
                    s=1; 
                    break;
                }
            }
            if (s==1) break;
        }
        if (s==1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
    }
    return 0;
} 