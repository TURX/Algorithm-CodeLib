#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ansArea, ansPeri;
char in;
bool map[1001][1001], lightoff[1001][1001], visited[1001][1001];

inline int calcAdja(const int& i, const int& j) {
    return (4 - map[i - 1][j] - map[i][j - 1] - map[i + 1][j] - map[i][j + 1]);
}

inline void dfs(const int& i, const int& j, const int& area, const int& peri) {
    if(visited[i][j] && lightoff[i][j]) return;
    if(!map[i][j]) {
        if(area > ansArea && peri > ansPeri) {
            ansArea = area;
            ansPeri = peri;
        }
        return;
    }
    lightoff[i][j] = true;
    visited[i][j] = true;
    int currPeri = calcAdja(i, j);
    dfs(i - 1, j, area + 1, peri + currPeri);
    dfs(i, j - 1, area + 1, peri + currPeri);
    dfs(i + 1, j, area + 1, peri + currPeri);
    dfs(i, j + 1, area + 1, peri + currPeri);
    visited[i][j] = false;
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> in;
            if(in == '#') map[i][j] = 1;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j]) {
                if(!lightoff[i][j]) dfs(i, j, 0, 0);
            }
        }
    }
    cout << ansArea << ' ' << ansPeri << endl;
    return 0;
}