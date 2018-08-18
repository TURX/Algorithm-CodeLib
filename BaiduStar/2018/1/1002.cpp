#include <iostream>
#include <string>
using namespace std;
int T, n, q, l, r, minNum = 100, contiNum;
string A;

/*
class RMQ
{
  public:
    inline void init()
    {
        for (int i = 1; i <= n; i++)
            cin >> d[i][0];
        for (int p = 1; (1 << p) <= n; p++)
            for (int i = 1; i + (1 << p) - 1 <= n; i++)
            {
                d[i][p] = min(d[i][p - 1], d[i + (1 << (p - 1))][p - 1]);
            }
        int low[N];
        low[1] = 1;
        for (int i = 2; i < N; i++)
            low[i] = low[i >> 1] + 1;
    }
}

inline int
calcDic(string &now)
{
    int ans = 0;
    for (int t = 0; t < now.length(); t++)
    {
        ans += (int)now[t];
    }
    return ans;
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    for (int casNum = 0; casNum < T; casNum++)
    {
        cin >> n >> q >> A;
        cout << "Case #" << casNum + 1 << ":" << endl;
        while (q--)
        {
            cin >> l >> r;
            for (int i = l; i <= r; i++)
            {
                if((int)A[i] < minNum) {
                    contiNum = 1;
                    minNum = A[i];
                    continue;
                }
                if((int)A[i] == minNum) {
                    contiNum++;
                    continue;
                }
            }
            cout << contiNum << endl;
            minNum = 100;
        }
    }
    return 0;
}
