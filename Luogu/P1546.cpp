// Online Tutorial: https://www.youtube.com/watch?annotation_id=annotation_2876488053&feature=iv&src_vid=oP2-8ysT3QQ&v=oP2-8ysT3QQ#t=5m58s

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 103
#define INF 0x7F

int N, graph[MAXN][MAXN], minM[MAXN];
bool visited[MAXN];

int main() {
    ios::sync_with_stdio(false);
    memset(minM, INF, sizeof(minM));
    minM[1] = 0;
    cin >> N;
    for(int x = 1; x <= N; x++) {
        for(int y = 1; y <= N; y++) {
            cin >> graph[x][y];
        }
    }
    for(int i = 1; i <= N; i++) {
        int k = 0;
        for(int j = 1; j <= N; j++) {
            if((!visited[j]) && (minM[j] < minM[k])) {
                k = j;
            }
        }
        visited[k] = true;
        for(int j = 1; j <= N; j++) {
            if((!visited[j]) && (minM[j] < minM[k])) {
                minM[j] = graph[k][j];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) ans += minM[i];
    cout << ans << endl;
    return 0;
}

/* Data
3
0 1 2
1 0 1
2 1 0
*/