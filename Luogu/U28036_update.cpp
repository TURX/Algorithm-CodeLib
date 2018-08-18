#include <iostream>
using namespace std;

unsigned n, Q, x, y, ans;
unsigned long long sequence[100003], triangle[1003][1003];

void generate() {
    for(int i = 0; i < 1003; i++) //对第一列和对角线赋值为1
    {
        triangle[i][1]=1;
        triangle[i][i]=1;
    }
    for(int i = 0; i < 1003; i++)
        for(int j = 1; j < i; j++)
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];//杨辉三角的关系
}

int main() {
    ios::sync_with_stdio(false);
    generate();
    cin >> n;
    for(unsigned t = 0; t < n; t++) {
        cin >> sequence[t];
    }
    cin >> Q;
    for(unsigned t = 0; t < Q; t++) {
        cin >> x >> y;
        ans = sequence[y];
        for(unsigned i = 0; i < x; i++) {
            ans += triangle[i + 1][t + 1] * sequence[i];
        }
        cout << ans % 998244353 << endl;
    }
    return 0;
}