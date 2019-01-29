#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 10001

/*
 * dfn为时间戳数组
 *  对于点u，如果dfn[u] != origin
 *  则点u在本轮匹配中还没有被匹配到
 *  似乎是查询去向节点
 * match[i]=j代表右侧的i号点与左侧的j号点匹配，即往回查来源节点
 */
int N, M, E, u, v, maximumMatch, dfn[MAXN], match[MAXN];
vector<int> G[MAXN];

bool dfs(int id, int origin) {
    for(int i = 0; i < G[id].size(); i++) { // 遍历所有连边
        int to = G[id][i];
        if(dfn[to] != origin) { // 可以匹配
            dfn[to] = origin;
            if((!match[to]) || dfs(match[to], origin)) { // 协商
                match[to] = id;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &N, &M, &E);
    while(E--) {
        scanf("%d%d", &u, &v);
        if(v > M || u > N) continue;
        G[u].push_back(v);
    }
    for(int t = 1; t <= N; t++) if(dfs(t, t)) maximumMatch++;
    printf("%d\n", maximumMatch);
    return 0;
}