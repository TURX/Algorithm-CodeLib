#include <iostream>
using namespace std;

#define MAXN 100003

int N;

struct Position {
    int x, y;
} I[MAXN], J[MAXN];

inline Position add(const Position& l, const Position& r, const int& mode) {
    Position ans;
    switch(mode) {
        case 0:
            ans.x = l.x + r.x;
            ans.y = l.y + r.y;
            break;
        case 1:
            ans.x = l.x + r.y;
            ans.y = l.y + r.x;
            break;
        case 2:
            ans.x = l.y + r.y;
            ans.y = l.x + r.x;
            break;
        case 3:
            ans.x = l.y + r.x;
            ans.y = l.x + r.y;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 1; t <= N; t++) cin >> I[t].x >> I[t].y;
    for(int t = 1; t <= N; t++) cin >> J[t].x >> J[t].y;
    for(int mode = 0; mode <= 3; mode++) {
        
    }
    return 0;
}