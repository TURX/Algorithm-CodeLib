// luogu-judger-enable-o2
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

int Log[100005], f[100005][16], n, m;
// f[x][y] ==> x : 字符 ; y : 层数

inline void Init()
{
    Log[1] = 0;
    rep(i, 2, n) Log[i] = Log[i >> 1] + 1;
}

inline void MakeST()
{
    rep(i, 1, n) scanf("%d", &f[i][0]);
    for (int p = 1; (1 << p) <= n; p++)
        for (int i = 1; i + (1 << p) - 1 <= n; i++)
            f[i][p] = max(f[i][p - 1],
                f[i + (1 << (p - 1))][p - 1]);
}

inline int Query(int l, int r)
{
    int p = Log[r - l + 1];
    return max(f[l][p], f[r - (1 << p) + 1][p]);
}

int main()
{
    scanf("%d %d", &n, &m);
    Init();
    MakeST();
    int l, r;
    while (m--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", Query(l, r));
    }
    return 0;
} 
