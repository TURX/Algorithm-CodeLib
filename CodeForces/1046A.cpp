#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

struct RobotBox {
    /* Description
     * x: position
     * r: radius of sight
     * q: IQ
    */
    unsigned long long x, r, q;
    inline friend bool operator <(const RobotBox& L, const RobotBox& R) {
        return L.x == R.x ? (L.r == R.r ? L.q < R.q : L.r < R.r) : L.x < R.x;
    }
} robot[10003];

/*
bool Access(const unsigned long long& x, const unsigned long long& r) {
    int ans[2];
    if(x - r < 0) ans[0] = 0; else ans[0] = x - r;
    if(x + r >= N) ans[1] = N - 1; else ans[1] = x + r;
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int t = 0; t < N; t++) {
        cin >> robot[t].x >> robot[t].r >> robot[t].q;
    }
    sort(robot, robot + N);
    for(int t = 1; t < N; t++) {
        if(robot[t].x )
    }
    return 0;
}