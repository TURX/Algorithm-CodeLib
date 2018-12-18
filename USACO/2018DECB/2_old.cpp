#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 101
#define MAXS 1001

bool nvacant[MAXN];
int N, S[MAXN], T[MAXN], minS = MAXS, maxT, occupied;

inline int avaliable() {
    for(int t = 0; t < occupied; t++) {
        if(!nvacant[t]) return t;
    }
    return -1;
}

inline void checkin() {
    int t = avaliable();
    if(t == -1) {
        nvacant[occupied] = true;
        occupied++;
    }
}

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 0; t < N; t++) {
        cin >> S[t] >> T[t];
        minS = min(minS, S[t]);
        maxT = max(maxT, T[t]);
    }
    for(int t = minS; t < maxT; t++) {
        for(int i = 0; i < N; i++) {
        }
    }
    return 0;
}