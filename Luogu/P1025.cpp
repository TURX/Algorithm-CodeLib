#include <iostream>
using namespace std;

int n, k, ans;

void dfs(int now, int lastnum) {
    if(now == k) {
        if(n > lastnum || n <= 0) return;
        ans++;
        return;
    }
    for(int i = 1; i <= lastnum; i++) {
        n -= i;
        dfs(now + 1, i);
        n += i;
    }
}

int main() {
    cin >> n >> k;
    dfs(1, 10000);
    cout << ans << endl;
    return 0;
}