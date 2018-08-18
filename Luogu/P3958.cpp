// https://www.luogu.org/blog/wohaocaia/solution-p3958

#include <iostream>
// #include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
bool ability;
int T, n, h, x, y, z, targetT, targetU, ufset[1003];
long long r;
struct Point {
    long long x, y, z;
} cheeseHole[1003];

vector<int> touchTop, touchBottom;

inline void variableInit(const int& n) {
    fill(cheeseHole, cheeseHole + n + 1, Point{0, 0, 0});
    touchTop.clear();
    touchBottom.clear();
    touchTop.push_back(0);
    touchBottom.push_back(0);
    ability = false;
}

inline int find(int x) {
    if(x != ufset[x]) ufset[x] = find(ufset[x]);
    return ufset[x];
} // Route Compression + Union-Find

inline void ufsetInit(int n) {
    for(int t = 1; t <= n; t++) {
        ufset[t] = t;
    }
}

inline double dist(const Point& a, const Point& b) {
    return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)) + ((a.z - b.z) * (a.z - b.z)));
}

int main() {
    ios::sync_with_stdio(false);
    // scanf("%d", &T);
    cin >> T;
    for(int casNum = 0; casNum < T; casNum++) {
        // scanf("%d%ld%ld", &n, &h, &r);
        cin >> n >> h >> r;
        variableInit(n);
        ufsetInit(n);
        for(int t = 1; t <= n; t++) {
            // scanf("%ld%ld%ld", &cheeseHole[t].x, &cheeseHole[t].y, &cheeseHole[t].z);
            cin >> cheeseHole[t].x >> cheeseHole[t].y >> cheeseHole[t].z;
            if(cheeseHole[t].z + r >= h) {
                touchTop.push_back(t);
            }
            if(cheeseHole[t].z - r <= 0) {
                touchBottom.push_back(t);
            }
            for(int u = 1; u <= t; u++) {
                if(dist(cheeseHole[t], cheeseHole[u]) <= 2 * r) {
                    targetT = find(t);
                    targetU = find(u);
                    if(targetT != targetU) {
                        ufset[targetT] = targetU;
                    }
                }
            }
        }
        for(int i = 1; i <= touchTop.size() - 1; i++) {
            for(int j = 1; j <= touchBottom.size() - 1; j++) {
                if(find(touchTop[i]) == find(touchBottom[j])) {
                    ability = true;
                    break;
                }
            }
            if(ability) break;
        }
        switch(ability) {
            case false:
                cout << "No" << endl;
                break;
            case true:
                cout << "Yes" << endl;
                break;
        }
    }
    return 0;
}