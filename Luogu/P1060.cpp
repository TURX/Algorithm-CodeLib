#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;
struct data {
	int p,v;
	int sum(){return v*p;}
};
int n,m;
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	data d[m];
	for(int t=0;t<m;t++) cin>>d[t].v>>d[t].p;
	int f[n];
	memset(f,0,n);
	// Templete
	for (int i = 0; i < m; i++) for (int j = n - 1; j >= 0; j--) if (d[i].v <= j) f[j] = max(f[j-d[i].v]+d[i].sum(), f[j]);
	cout<<f[n-1]<<endl;
	return 0;
}
/*
#include <stdio.h>  
#define N 1050017
int v[25],w[25],f[25][30000];
int wei[N],val[N],f[N];
int i, j, n, m;
int oldmain()  {
    cin>>n>>m;
    while(scanf("%d",&n)!=EOF)
    {  
        scanf("%d", &m);
        for(i=0; i<n; i++)  
            scanf("%d%d", &wei[i],&val[i]);//wei[i]为重量，val[i]为价值  
        for(i=0; i<n; i++)  
        {  
            for(j=m; j>=wei[i]; j--)  
                f[j] = max(f[j], f[j-wei[i]]+val[i]);  
        }  
        printf("%d\n",f[m]);  
    }
    return 0;  
} 
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
}*/
