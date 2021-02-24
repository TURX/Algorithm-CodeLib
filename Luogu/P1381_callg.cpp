// luogu-judger-enable-o2
#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>

using namespace std;

inline void chkmin(int &x, int y) { (x > y) && (x = y); }

const int MAXN = 1007, MAXM = 100007;

unordered_map<string, int> map;
int n, m, a[MAXM], cnt[MAXN];
bitset<MAXN> have;

inline int count() {
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (bool)cnt[i];
    return ans;
}

int main() {
    cin >> n;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        map[str] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> str;
        if (map.count(str)) have[a[i] = map[str]] = true;
        else a[i] = 0;
    }
    int ansCnt = have.count();
    if (not ansCnt) return ((cout << 0 << endl << 0 << endl), 0);
    
    int l = 0, r = 0, len = MAXM;
    cnt[a[0] = 0] = 233;
    while (++r <= m) {
        cnt[a[r]]++;
        while (not a[l]) l++;
        while (cnt[a[l]] > 1) cnt[a[l++]]--;
        if (count() == ansCnt) chkmin(len, r - l + 1);
    }
    cout << ansCnt << endl << len << endl;
    return 0;
}