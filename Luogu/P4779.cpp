// P3371 => P4779
// https://m-sea.blog.luogu.org/solution-p4779
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

bool enrolled[100003]; long long dist[100003]; int source[100003], head[100003];
int N, M, S, u, v, w, graphCnt;

struct Edge {
    int v; // Destination
    long long w; // Weight
    int next;
} graph[200003];

struct Node {
    int u;
    long long d;
    inline bool operator <(const Node& rhs) const {
        // if(d == -1) return true;
        return d > rhs.d;
    }
};

inline void Dijkstra() {
    for(int t = 1; t <= N; t++) dist[t] = LONG_LONG_MAX;
    dist[S] = 0;
    priority_queue<Node> Q;
    Q.push({S, 0});
    while(!Q.empty()) {
        Node current = Q.top();
        Q.pop();
        int u = current.u; long long d = current.d;
        if(d != dist[u]) continue;
        for(int t = head[u]; t; t = graph[t].next) {
            int v = graph[t].v; long long w = graph[t].w;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                Q.push({v, dist[v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> S;
    for(int t = 0; t < M; t++) {
        cin >> u >> v >> w;
        graph[graphCnt++] = {v, w, head[u]};
        head[u] = graphCnt;
    }
    Dijkstra();
    for(int t = 1; t <= N; t++) cout << dist[t] << " ";
    cout << endl;
    return 0;
}