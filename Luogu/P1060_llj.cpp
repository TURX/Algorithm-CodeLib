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
    Thing things[m+5];//�࿪һ��
	for (int i = 0; i < m; i++) scanf("%d %d", &things[i].v, &things[i].p);
    int f[N+5];//f(i,j)��ʾֻ��jԪʱ�����Ž�
	memset(f, 0, sizeof(f));//��ʼ��
	
	//ģ��
    for (int i = 0; i < m; i++)//��Ʒ
        for (int j = N - 1; j >= 0; j--)//Ǯ������������
            if (things[i].v <= j)//�ŵ���
                f[j] = max(f[j-things[i].v]+things[i].sum(), f[j]);//��Ϊ�ǹ�������
			//else
				//f[j];��仰������ʡ��
    printf("%d", f[N-1]);
    return 0;
}
