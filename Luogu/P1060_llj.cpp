#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;
struct Thing
{
    int v, p;
    int sum(){return v*p;}
};
int max(int x, int y){return x > y ? x : y;}
int main()
{
    int N, m;
    scanf("%d %d", &N, &m);
    Thing things[m+5];//多开一点
	for (int i = 0; i < m; i++) scanf("%d %d", &things[i].v, &things[i].p);
    int f[N+5];//f(i,j)表示只有j元时的最优解
	memset(f, 0, sizeof(f));//初始化
	
	//模版
    for (int i = 0; i < m; i++)//物品
        for (int j = N - 1; j >= 0; j--)//钱数，滚动数组
            if (things[i].v <= j)//放得下
                f[j] = max(f[j-things[i].v]+things[i].sum(), f[j]);//因为是滚动数组
			//else
				//f[j];这句话无意义省略
    printf("%d", f[N-1]);
    return 0;
}
