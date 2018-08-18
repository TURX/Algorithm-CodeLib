#include <iostream>
using namespace std;
int map[40][40];
int N;

struct Last {
    int x, y;
} last;

int main() {
    cin >> N;
    last.x = N / 2 + 1; last.y = 1;
    map[last.x][last.y] = 1;
    for(int k = 2; k <= N * N; k++) {
        if(last.y == 1 && last.x != N) {
            last.y = N; last.x++;
            map[last.x][last.y] = k;
            continue;
        }
        if(last.x == N && last.y != 1) {
            last.x = 1; last.y--;
            map[last.x][last.y] = k;
            continue;
        }
        if(last.y == 1 && last.x == N) {
            last.y++;
            map[last.x][last.y] = k;
            continue;
        }
        if(last.y != 1 && last.x != N) {
            if(!map[last.x + 1][last.y - 1]) {
                last.x++; last.y--;
            }
            else {
                last.y++;
            }
            map[last.x][last.y] = k;
            continue;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << map[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}