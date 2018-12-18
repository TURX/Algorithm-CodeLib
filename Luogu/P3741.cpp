// luogu-judger-enable-o2
#include <iostream>
#include <string>
using namespace std;

string a;
int ans, n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> a;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 'V' && a[i + 1] == 'K')
        {
            ans++;
            a[i] = 'X';
            a[i + 1] = 'X';
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 'X' && a[i] == a[i + 1])
        {
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}