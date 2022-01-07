#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 300005;
struct node
{
    int st, ed;
    bool friend operator < (node a, node b)
    {
        return a.st < b.st;
    }
} nod[maxn];
int main()
{
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
        cin>>nod[i].st>>nod[i].ed;
    sort(nod+1, nod+1+n);
    multiset<int> st;
    multiset<int>::iterator it;
    int ans = 0;
    for(int i=1; i<=n; ++i)
    {
        int stat = nod[i].st - m;
        while(st.size() && *st.begin() < stat)
            st.erase(st.begin());
        if(st.size() && *st.begin() <= nod[i].st)
            st.erase(st.begin());
        else
            ans ++;
        st.insert(nod[i].st+nod[i].ed);
    }
    cout<<n-ans<<endl;
    return 0;
}
