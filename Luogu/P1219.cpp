#include <iostream>
using namespace std;

int n, ans, solution[3][20], cnt;
bool horizontal[20], vertical[20], plu[30], sub[50];

void dfs(const int& now) {
    if(now == n + 1) {
        ans++;
        cnt++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(horizontal[now] || vertical[i] || plu[now + i] || sub[now - i + 20]) continue;
        horizontal[now] = true; vertical[i] = true; plu[now + i] = true; sub[now - i + 20] = true;
        solution[cnt][now] = i;
        dfs(now + 1);
        horizontal[now] = false; vertical[i] = false; plu[now + i] = false; sub[now - i + 20] = false;
        if(cnt <= 3) solution[cnt][now] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    dfs(1);
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= n; j++) {
            if(solution[i][j] == 0) solution[i][j] = solution[i - 1][j];
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}