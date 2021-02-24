/* Dijkstra's Algorithm: Single Source Shortest Path
 * Author: TURX
 * Target: https://www.luogu.org/problemnew/show/P4779
 * Resources:
 *  https://oi-wiki.org/graph/shortest-path/
 *  https://www.youtube.com/watch?v=lAXZGERcDf4
 *  https://github.com/mission-peace/interview/blob/master/src/com/interview/graph/DijkstraShortestPath.java
 * Teacher:
 *  LCX
 *  XiongXuan
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 100003
#define MAXM 200003

struct Point {
    int to;
    unsigned long long weight;
    inline bool operator <(const Point& rhs) const {
        return weight > rhs.weight; // Put the priority on the less weight between LHS and RHS
    }
}; // This data structure is shared between both vertex and edge parts
vector<Point> g[MAXN]; // Use Point vector array to store edges

bool visited[MAXN];
int N, M, S, u, v;
unsigned long long w, dist[MAXN];

inline void Dijkstra() {
    priority_queue<Point> Q;
    Q.push({S, 0}); // Start from S, no previous weight
    dist[S] = 0; // The distance between S and S is 0
    while(!Q.empty()) { // Travel all vertexes
    // for(int i = 1; i <= N; i++) { // Travel all vertexes
        Point u = Q.top(); Q.pop();// The minimal edge
        if(visited[u.to]) continue;
        visited[u.to] = true;
        for(int j = 0; j < g[u.to].size(); j++) { // Apply the minimal edge to all able vertexes
            if(dist[g[u.to][j].to] > dist[u.to] + g[u.to][j].weight) {
	            dist[g[u.to][j].to] = dist[u.to] + g[u.to][j].weight;
	            Q.push({g[u.to][j].to, dist[g[u.to][j].to]});
            }
            /*
                if(g[u.to][j].weight + dist[u.to] < dist[j]) { // If there's a shorter path that can apply to vertex J
                    dist[g[u.to][j].to] = dist[j] + dist[u.to]; // Update the distance to vertex J
                    Q.push({g[u.to][j].to, dist[g[u.to][j].to]}); // Add vertex J to waiting list
                }
            */
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> S;
    for(int t = 0; t < M; t++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    } // Input edges
    memset(dist, 0x3f, sizeof(dist)); // Set distances to infinite
    Dijkstra(); // Run Dijkstra's algorithm
    for(int t = 1; t <= N; t++) cout << dist[t] << " "; // Output
    cout << endl;
    return 0;
}