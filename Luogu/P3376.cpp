/*
 * 网络流：EK算法
 * Network Flow: Edmonds-Karp Algorithm
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
 * A: 从起始点到i点的总流量
 * P: 最短路树上P的入边编号
    * 为什么要最短路？
    * 
 */
int N, M, S, T;
vector<Edge> E;
vector<int> G[MAXN];
int A[MAXN], P[MAXN];

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

inline int maxFlow(const int& S, const int& T) {
    int ans = 0;
    while(true) { // BFS
        memset(A, 0, sizeof(A)); // 因为A会多次使用所以必须置0
        queue<int> Q; // 创建BFS队列
        Q.push(S); // 将起点插入
        A[S] = INF; // 流量设为无限，因为还未计算，且这样可以起到一个类似于visited数组的限制访问的效果
        while(!Q.empty()) {
            int x = Q.front(); // 从队首开始BFS
            Q.pop();
            for(int t = 0; t < G[x].size(); t++) { // 遍历连接当前x点的所有边
                Edge& e = E[G[x][t]];
                if(!A[e.v] && e.c > e.f) { // 判断A[e.v]是防止访问到已经访问过的边，e.c > e.f是判断是否满流
                    P[e.v] = G[x][t]; // P是什么？
                    A[e.v] = min(A[x], e.c - e.f); // 求出最大的占用，但此处用最小是因为不能超过容量
                    Q.push(e.v); // 进入BFS序列
                }
            }
            if(A[T]) break; // 终点算出了流量的话就可以结束此次BFS（即便Q并不是空的，因为下次BFS会从此次剩下的节点的front重新开始，即回溯）
        }
        if(!A[T]) break; // 如果Q空了，且A[T]没有数据的话，说明此次搜索不仅到达终点，算法也已经结束（为什么？
        for(int u = T; u != S; u = E[P[u]].u) {
            E[P[u]].f += A[T]; // 因为终点的流量是当前可能情况的最大流，所以给每个节点加上的流量一定不会超过它的容量
            E[P[u] ^ 1].f -= A[T]; // 给反向边减去流量
        }
        ans += A[T]; // 汇点有来自不同路径的流量，所以ans将流量加起
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