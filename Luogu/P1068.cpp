#include<iostream>
#include<algorithm>
using namespace std;
int n,m,least,passedpeople,k[100],s[100];
//int d[100][2]; // 1: k 2: s
void selectionSort(int (&A)[100], int (&B)[100], int N)
{
    int i, j, t, sw = 0, minj;
    for (i = 0; i < N - 1; i++)
    {
        minj = i;
        for (j = i; j < N; j++)
        {
            if (A[j] > A[minj]) minj = j;
        }
        swap(A[i],A[minj]);
        swap(B[i],B[minj]);
        if (i != minj) sw++;
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int t=0;t<n;t++) cin>>k[t]>>s[t];
	//for(int t=0;t<n;t++) cin>>d[t][0]>>d[t][1];
	passedpeople=m*1.5;
	//sort(s,s+n);
	selectionSort(s,k,n);
	for(int t=0;t<n;t++) {
		if(s[t]==s[t+1]) {
			if(k[t]>k[t+1]) {
				swap(k[t],k[t+1]);
				swap(s[t],s[t+1]);
			}
		}
	}
	least=s[passedpeople];
	cout<<least<<" "<<passedpeople<<endl;
	for(int t=0;t<=passedpeople;t++) cout<<k[t]<<" "<<s[t]<<endl;
	return 0;
}
