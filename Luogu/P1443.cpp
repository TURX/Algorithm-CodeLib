#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAXN 401

struct E {
    int x, y, layer;
};

int N, M, hajimeX, hajimeY, dist[401][401];
bool vis[401][401];

inline bool verifyX(const int& x) {
    return x > 0 && x <= N;
}

inline bool verifyY(const int& y) {
    return y > 0 && y <= M;
}

void bfs() {
    queue<E> Q;
    Q.push({hajimeX, hajimeY, 0});
    while(!Q.empty()) {
        E current = Q.front(); Q.pop();
        if(vis[current.x][current.y]) return;
        dist[current.x][current.y] = current.layer;
        vis[current.x][current.y] = true;
        if(verifyX(current.x - 2) && verifyY(current.y + 1)) Q.push({current.x - 2, current.y + 1, current.layer + 1});
        if(verifyX(current.x - 1) && verifyY(current.y + 2)) Q.push({current.x - 1, current.y + 2, current.layer + 1});
        if(verifyX(current.x + 2) && verifyY(current.y + 1)) Q.push({current.x + 2, current.y + 1, current.layer + 1});
        if(verifyX(current.x + 1) && verifyY(current.y + 2)) Q.push({current.x + 1, current.y + 2, current.layer + 1});
        if(verifyX(current.x + 2) && verifyY(current.y - 1)) Q.push({current.x + 2, current.y - 1, current.layer + 1});
        if(verifyX(current.x + 1) && verifyY(current.y - 2)) Q.push({current.x + 1, current.y - 2, current.layer + 1});
        if(verifyX(current.x - 2) && verifyY(current.y - 1)) Q.push({current.x - 2, current.y - 1, current.layer + 1});
        if(verifyX(current.x - 1) && verifyY(current.y - 2)) Q.push({current.x - 1, current.y - 2, current.layer + 1});
    }
}

int main() {
    memset(dist, -1, sizeof(dist));
    cin >> N >> M >> hajimeX >> hajimeY;
    bfs();
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            printf("%5d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}