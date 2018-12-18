#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 103
#define INF 0x7FFFFFFF

char inputBuffer;
int N, hajimeX, hajimeY, owariY, owariX, minimumTurn = INF;
bool matrix[MAXN][MAXN];

inline bool add(const int& fromX, const int& fromY, const int& destX, const int& destY, const int& symbol) {
    /* SYMBOLS
     * 0: Initial
     * 1: Up
     * 2: Down
     * 3: Left
     * 4: Right
     */
    if(fromY - destY == 1 && symbol != 1) return true;
    if(destY - fromY == 1 && symbol != 2) return true;
    if(fromX - destX == 1 && symbol != 3) return true;
    if(destX - fromX == 1 && symbol != 4) return true;
    return false;
}

void dfs(const int& y, const int& x, const int& symbol, int turn) {
    if(turn >= minimumTurn) return;
    if(y == owariY && x == owariX) {
        minimumTurn = min(minimumTurn, turn);
        return;
    }
    if(y >= N || x >= N || y < 0 || x < 0) return; // Overflow check
    if(!matrix[y][x] && symbol) return; // Avaliablity check
    matrix[y][x] = false;
    dfs(y + 1, x, 1, turn + add(y, x, y + 1, x, symbol));
    dfs(y - 1, x, 2, turn + add(y, x, y - 1, x, symbol));
    dfs(y, x + 1, 3, turn + add(y, x, y, x + 1, symbol));
    dfs(y, x - 1, 4, turn + add(y, x, y, x - 1, symbol));
    matrix[y][x] = true;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            while(inputBuffer = getchar()) {
                if(inputBuffer == ' ' || inputBuffer == '\n') continue;
                switch(inputBuffer) {
                    case 'A':
                        hajimeY = i; hajimeX = j;
                        break;
                    case 'B':
                        owariX = i; owariY = j;
                        break;
                    case '.':
                        matrix[i][j] = true;
                        break;
                    case 'y':
                        break;
                }
                break;
            }
        }
    }
    dfs(hajimeX, hajimeY, 0, 0);
    if(minimumTurn == INF) {
        cout << "-1" << endl;
    } else {
        cout << minimumTurn << endl;
    }
    return 0;
}