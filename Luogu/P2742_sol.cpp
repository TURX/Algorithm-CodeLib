// P2742.cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    double x, y;
    bool operator< (const Point& rhs) {
        return (x == rhs.x) ? (y < rhs.y) : (x < rhs.x);
    }
};

int N;
double totLen, x, y;
vector<Point> G;
deque<int> prs;

inline double squareCalc(const double& num) {
    return num * num;
}

inline double lenCalc(const Point& lhs, const Point& rhs) {
    return sqrt(squareCalc(rhs.x - lhs.x) + squareCalc(rhs.y - lhs.y));
}

inline bool inOrderCmp(const Point& lhs, const Point& rhs) {
    return (lhs.x == rhs.x) ? (lhs.y < rhs.y) : (lhs.x < rhs.x);
}

inline double crossProductRaw(const Point& lhs, const Point& rhs) { // Edge
    double ans = lhs.x * rhs.y - rhs.x * lhs.y;
    return ans;
}

inline double crossProduct(const Point& a, const Point& b, const Point& c) {
    double lx = b.x - a.x;
    double ly = b.y - a.y;
    double rx = c.x - b.x;
    double ry = c.y - b.y;
    return crossProductRaw({lx, ly}, {rx, ry});
}

bool judge(int a, int b, int c) {
    return crossProduct(G[a], G[b], G[c]);
}
int main() {
    scanf("%d", &N);
    while(N--) {
        scanf("%lf%lf", &x, &y);
        G.push_back({x, y});
    }
    sort(G.begin(), G.end());
    prs.push_front(0), prs.push_front(1);
    for (int i = 2; i < N; i++)
    {
        while (prs.size() > 1 && !judge(prs[0], prs[1], i))
            prs.pop_front();
        prs.push_front(i);
    }
    for (int i = 0; i < prs.size() - 1; i++)
        totLen += lenCalc(G[prs[i]], G[prs[i + 1]]);
    prs.clear();
    prs.push_front(0), prs.push_front(1);
    for (int i = 2; i < N; i++)
    {
        while (prs.size() > 1 && judge(prs[0], prs[1], i))
            prs.pop_front();
        prs.push_front(i);
    }
    for (int i = 0; i < prs.size() - 1; i++)
        totLen += lenCalc(G[prs[i]], G[prs[i + 1]]);
    printf("%.2lf", totLen);
    return 0;
}