#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 101
#define MAXS 1001

int N, S[MAXN], T[MAXN], B[MAXN], minS = MAXS, maxT, occupied, maxOccupied;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 0; t < N; t++) {
        cin >> S[t] >> T[t] >> B[t];
        minS = min(minS, S[t]);
        maxT = max(maxT, T[t]);
    }
    for(int t = minS; t < maxT; t++) {
        for(int i = 0; i < N; i++) {
            if(S[i] == t) occupied += B[i];
            if(T[i] == t) occupied -= B[i];
            maxOccupied = max(maxOccupied, occupied);
        }
    }
    cout << maxOccupied << endl;
    return 0;
}