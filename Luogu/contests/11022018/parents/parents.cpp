#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 203
typedef long long LL;

LL N, M, motivation, motivationMax, motivMap[MAXN][MAXN], philo;
LL T, xi, yi;
bool blockOpen[MAXN][MAXN], blockVisited[MAXN][MAXN];

inline void addMotivation(const LL& val) {
    if(motivation + val > motivationMax) {
        motivation = motivationMax;
        return;
    }
    motivation += motivationMax;
}

inline void openBlock(const LL& x, const LL& y) {
    blockOpen[x - 1][y - 1] = true;
    blockOpen[x][y - 1] = true;
    blockOpen[x + 1][y - 1] = true;
    blockOpen[x - 1][y] = true;
    blockOpen[x][y] = true;
    blockOpen[x + 1][y] = true;
    blockOpen[x - 1][y + 1] = true;
    blockOpen[x][y + 1] = true;
    blockOpen[x + 1][y + 1] = true;
}

inline void dig(const LL& x, const LL& y) {
    openBlock(x, y);
    blockVisited[x][y] = true;
    if(motivMap[x][y] <= 0) {
        motivation -= 10;
        philo++;
    } else {
        addMotivation(motivMap[x][y]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> motivationMax;
    motivation = motivationMax;
    for(LL x = 1; x <= N; x++) {
        for(LL y = 1; y <= M; y++) {
            cin >> motivMap[x][y];
        }
    }
    for(LL x = 1; x <= N; x++) {
        for(LL y = 1; y <= M; y++) {
            cin >> blockOpen[x][y];
        }
    }
    cin >> T;
    for(LL t = 0; t < T; t++) {
        cin >> xi >> yi;
        if((!blockOpen[xi][yi]) || blockVisited[xi][yi] || (motivation < 10 && motivMap[xi][yi] <= 0)) {
            cout << "-1 -1" << endl;
            return 0;
        }
        dig(xi, yi);
    }
    cout << motivation << ' ' << philo * 10 << endl;
    return 0;
}