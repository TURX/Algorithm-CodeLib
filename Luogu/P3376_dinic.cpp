/*
 * 网络流：Dinic算法
 * Network Flow: Dinic Algorithm
 * 
 * Osusume Shiryou: https://www.luogu.org/blog/user48036/solution-p3376
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAXN 10001 // 最大点数
#define MAXM 100001 // 最大边数
#define INF 0x7ffffff // 无限

struct Edge { // 结构体存边
    /*
     * u: 入点编号
     * v: 出点编号
     * c: 容量
     * f: 流量
     */
    int u, v, c, f;
};

/*
 * N: 点数
 * M: 边数
 * S: 起始点
 * T: 终止点
 * E: 图中边的详细信息
 * G: 点映射存储有向边
 * D: 深度
 */
int N, M, S, T;
vector<Edge> E;
vector<int> G[MAXN];
int D[MAXN];

/*
 * u: 入点编号
 * v: 出点编号
 * c: 容量
 */
int u, v, c;

inline void add(const int& u, const int& v, const int& c) {
    E.push_back({u, v, c, 0}); // 顺着走的边有可用流量
    E.push_back({v, u, 0, 0}); // 逆着走不会有可用流量
    G[u].push_back(E.size() - 2); // 按照加边顺序可以推出这两行代码
    G[v].push_back(E.size() - 1);
}

// BFS用来分层
inline bool bfs(const int& S, const int& T) {
    memset(D, INF, sizeof(D));
    D[S] = 0; // 清空起点深度
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()) {
        int x = Q.front(); // 从队首开始BFS
        Q.pop();
        for(int t = 0; t < G[x].size(); t++) { // 遍历连接当前x点的所有边
            Edge& e = E[G[x][t]];
            if(D[e.v] > INF && e.f) { // f在此处用来做标记 是正图还是返图 
                D[e.v] = D[x] + 1;
                Q.push(e.v); // 进入BFS序列
            }
        }
    }
    return D[T] < INF;
}

// DFS找增加的流的量
inline int dfs(const int& current, const int& T, int L) { // L: Limit
    if(!L || current == T) return L;
    int flow = 0, f;
    for(int t = 0; t < G[current].size(); t++) {
        Edge& e = E[G[current][t]];
        f = dfs(e.v, T, min(L, e.f));
        if(D[e.v] == D[current] + 1 && f) {
            flow += f;
            L -= f;
            e.f -= f;
            E[G[current][t] ^ 1].f += f;
            if(!L) break;
        }
    }
    return flow;
}

inline int maxFlow(const int& S, const int& T) {
    int ans = 0;
    while(bfs(S, T)) {
        ans += dfs(S, T, INF);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> S >> T;
    for(int t = 0; t < M; t++) {
        cin >> u >> v >> c;
        add(u, v, c);
    }
    cout << maxFlow(S, T) << endl;
    return 0;
}