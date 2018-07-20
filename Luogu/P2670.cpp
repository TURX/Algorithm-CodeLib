#include <cstdio>
#include <iostream>
using namespace std;

int n,m;
char arr[108][108];
int answ[108][108];

bool check(char target) {
    if(target=='*') return 1;
    return 0;
}

int process(int x,int y) {
    return (int)(check(arr[x-1][y-1]) + check(arr[x-1][y]) + check(arr[x][y-1]) + check(arr[x+1][y-1]) + check(arr[x+1][y+1]) + check(arr[x][y+1]) + check(arr[x-1][y+1]) + check(arr[x+1][y]));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            arr[i][j] = getchar();
            answ[i][j] = process(i, j);
        }
        getchar();
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            answ[i][j] = process(i, j);
        }
    }
    /*
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j]=='*') putchar('*'); else putchar(answ[i][j]+'0');
        }
        putchar('\n');
    }
    */
   for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= m; j++) {
           cout << arr[i][j] << " " << endl;
           /*if(arr[i][j] == '*') cout << '*';
           else cout << answ[i][j];*/
       }
       cout << endl;
   }
   /*
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
        	putchar(answ[i][j]+'0');
        }
        putchar('\n');
    }
    */
   return 0;
}
