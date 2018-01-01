#include<iostream>
#include<algorithm>
using namespace std;
int n,m,fee=0; // n是需要牛奶的总数，m是提供牛奶的农民个数
struct data {
	int p; // 单价
	int a; // 数量
} d[5000]; // 定义结构体存储单价和数量
bool cmp(data lhs, data rhs) { // 自定义比较函数
    return lhs.p < rhs.p; // 返回比较
}
int main() {
	ios::sync_with_stdio(false); // iostream 快过 cstdio 的函数
	cin>>n>>m; // 输入
	for(int t=0;t<m;t++) cin>>d[t].p>>d[t].a; // 输入 第 2 到 M+1 行:每行二个整数:Pi（单价） 和 Ai（数量）。
	sort(d,d+m,cmp); // stl_algo.h: sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)，故此处__comp为自定义比较函数，按返回值进行排序
	for(int t=0;t<m;t++) {
		if(n>=d[t].a) // 数量未到达要求
        {
            fee+=d[t].a*d[t].p; // 计算费用
            n-=d[t].a; // 已经完成，减少数量要求
        }
        else // 已到达数量要求
        {
            fee+=d[t].p*n; // 最后计算费用
            break; // 跳出
        }
	}
	cout<<fee<<endl; // 输出费用
}
