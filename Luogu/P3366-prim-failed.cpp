// https://tbr-blog.blog.luogu.org/solution-p3366
#include <iostream>
using namespace std;
#define INF 0x7fffffff
int N, M, u, v, w, cost[5001][5001], v2[5001], minTotalLen, minCurrent, current;
bool connected[5001];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++)
            cost[i][j] = INF;
    for(int t = 0; t < M; t++) {
        cin >> u >> v >> w;
        if(cost[u][v] > w)
            cost[u][v] = cost[v][u] = w;
    }
    for(int t = 0; t < N; t++) {
        v2[t] = cost[0][t];
    }
    connected[0] = true;
    for(int t = 0; t < N - 1; t++) {
        minCurrent = INF;
        for(int i = 0; i < N; i++) {
            if(!connected[i] && cost[0][i] < minCurrent) {
                minCurrent = v2[i];
                current = i;
            }
        }
        minTotalLen += minCurrent;
        for(int i = 0; i < N; i++)
            if(v2[i] > cost[current][i] && !connected[i]) {
                v2[i] = cost[current][i];
            }
        connected[current] = true;
    }
    cout << minTotalLen << endl;
    return 0;
}