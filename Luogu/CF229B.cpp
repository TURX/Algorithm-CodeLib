#define INF = 1e12;
#include <iostream>
#include <queue>
using namespace std;
int dis[100003], vis[100003], head[100003], n, u;
queue<int> q;

struct Node {
    int dest;
    int weig;
    int next;
} g;

int main() {
    cin >> n >> m;
    fill(dis + 1, dis + n, INF);
    q.push(0);
    vis[0] = true;
    dis[0] = 0;
    while(!que.empty) {
        u = q.front();
        q.pop();
        vis[u] = false;
        for(register int i = head[u]; i != 1; i = g[i].next) {
            int v = g[i].dest;
            int w = g[i].weig;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}