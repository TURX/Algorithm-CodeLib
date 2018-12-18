#include <iostream>
#include <queue>
using namespace std;

#define MAXN 100003 // N: Maximum number of points.
#define MAXM 200003 // M: Maximum number of edges.

int N, M, S, head[MAXN], edgeCnt;
int u, v; long long w, dist[MAXN];

struct Node {
    int to;
    int next;
    long long weight;
} e[MAXN];

struct Element {
    int number;
    long long dist;
    friend bool operator <(const Element& lhs, const Element& rhs) {
        return lhs.number > rhs.number;
    }
};

inline void addEdge(const int& u, const int& v, const long long& w) {
    e[edgeCnt++].to = v;
    e[edgeCnt].next = head[u];
    e[edgeCnt].weight = w;
    head[u] = edgeCnt;
}

inline bool relax(const int& u, const int& v, const long long& w) {
    if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        return true;
    } else return false;
}

inline void dijkstra() {
    priority_queue<Element> H;
    H.push({S, 0});
    dist[S] = 0;
    for(int i = 1; i <= N; i++) {
        int number = H.top().number;
        long long weight = H.top().dist;
        H.pop();
        for(int t = head[u]; t; t = e[t].next) {
            if(relax(u, e[i].to, w)) {
                H.push({e[i].to, dist[e[i].to]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> S;
    for(int t = 0; t < M; t++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dijkstra();
    for(int t = 1; t <= N; t++) cout << dist[t] << " ";
    cout << endl;
    return 0;
}