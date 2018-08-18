// https://www.luogu.org/blog/wozaixuexi/solution-p2831

#include <iostream>
#include <cmath>
using namespace std;

const double minDiff = 1e-8;
int T, N, M;

bool judgeEqual(const double& a, const double& b) {
    return fabs(a - b) < minDiff;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for(int casNum = 0; casNum < T; casNum++) {
        cin >> N >> M;
    }
    return 0;
}