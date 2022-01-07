
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;
 
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 7e4 + 5, MOD = 1e9 + 7;
 
int T, cas = 0;
int n, p, q, x;
int b[N], hs[N], ans[N];
 
int main(){
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
 
	si(T);
	while(T --) {
		siii(n, p, q);
		p ++, q ++;
		mem(hs, 0);
		for(int i = 1; i <= p; i ++) { 
			si(x);
			hs[x] = i;
		}
		int idx = 0;
		for(int i = 1; i <= q; i ++) {
			si(x);
			if(hs[x]) b[idx ++] = hs[x];
		}
 
		int pos = 0;
		ans[0] = 0;
		for(int i = 0; i <= idx; i ++) {
			if(b[i] > ans[pos]) ans[++ pos] = b[i];
			else if(b[i] < ans[pos]) {
				int mid = lower_bound(ans, ans + pos, b[i]) - ans;
				ans[mid] = b[i];
			}
		}
		printf("Case %d: %d\n", ++ cas, pos);
 
	}
 
    return 0;
}