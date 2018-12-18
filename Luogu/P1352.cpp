// P1352 没有上司的舞会
// Tag: DP with tree structure

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 6001

struct Crew {
    int boss, pleasure;
    vector<int> children;
} clerk[MAXN];

int N, L, K, dp[MAXN][2], master;
// dp[who the person is][if he will go]

int getMaster(const int& current) {
    return (!clerk[current].boss) ? current : getMaster(clerk[current].boss);
}

void dfs(const int& S) {
    dp[S][1] = clerk[S].pleasure;
    for(int t = 0; t < clerk[S].children.size(); t++) {
        dfs(clerk[S].children[t]);
        dp[S][0] += (max(dp[clerk[S].children[t]][1], dp[clerk[S].children[t]][0]));
        dp[S][1] += (dp[clerk[S].children[t]][0]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 1; t <= N; t++) {
        cin >> clerk[t].pleasure;
    }
    for(int t = 1; t < N; t++) {
        cin >> L >> K;
        clerk[L].boss = K;
        clerk[K].children.push_back(L);
    }
    master = getMaster(1);
    dfs(master);
    cout << max(dp[master][0], dp[master][1]) << endl;
    return 0;
}