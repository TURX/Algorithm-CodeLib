// luogu-judger-enable-o2
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 10001;

struct Point {
    double x, y;
};

struct Stack {
    int siz = 0, data[MAXN];
    void push(const int& x) {
        data[++siz] = x;
    }
    void pop() {
        if(siz) siz--;
    }
    int top() {
        if(siz <= 0) return -1;
        return data[siz];
    }
    bool empty() {
        return !siz;
    }
    int size() {
        return siz;
    }
    int beforeTop() {
        if(siz - 1 <= 0) return -1;
        return data[siz - 1];
    }
} inOrder, antiOrder;

int N, bIndex;
int aIndex = -1;
double x, y, totLen;
vector<Point> G;

inline bool inOrderCmp(const Point& lhs, const Point& rhs) {
    return lhs.x < rhs.x;
}

inline bool antiOrderCmp(const Point& lhs, const Point& rhs) {
    return !inOrderCmp(lhs, rhs);
}

inline double crossProductRaw(const Point& lhs, const Point& rhs) { // Edge
    double ans = lhs.x * rhs.y - rhs.x * lhs.y;
    return ans;
}

inline double crossProductInOrder(const Point& a, const Point& b, const Point& c) {
    double lx = b.x - a.x;
    double ly = b.y - a.y;
    double rx = c.x - b.x;
    double ry = c.y - b.y;
    return crossProductRaw({lx, ly}, {rx, ry});
}

inline double crossProductAntiOrder(const Point& a, const Point& b, const Point& c) {
    double lx = a.x - b.x;
    double ly = a.y - b.y;
    double rx = b.x - c.x;
    double ry = b.y - c.y;
    return crossProductRaw({lx, ly}, {rx, ry});
}

inline double squareCalc(const double& num) {
    return num * num;
}

inline double lenCalc(const Point& lhs, const Point& rhs) {
    return sqrt(squareCalc(abs(rhs.x - lhs.x)) + squareCalc(abs(rhs.y - lhs.y)));
}

int main() {
    cin >> N;
    while(N--) {
        cin >> x >> y;
        G.push_back({x, y});
    }
    inOrder.push(0), inOrder.push(1), antiOrder.push(0), antiOrder.push(1);
    sort(G.begin(), G.end(), inOrderCmp);
    for(int t = 2; t < G.size(); t++) {
        while(crossProductInOrder(G[inOrder.beforeTop()], G[inOrder.top()], G[t]) <= 0 && !inOrder.empty()) {
            inOrder.pop();
        }
        inOrder.push(t);
    }
    while(!inOrder.empty()) {
        if(aIndex == -1) {
            aIndex = inOrder.top();
            inOrder.pop();
        } else {
            aIndex = bIndex;
        }
        bIndex = inOrder.top();
        inOrder.pop();
        totLen += lenCalc(G[aIndex], G[bIndex]);
    }
    sort(G.begin(), G.end(), antiOrderCmp);
    for(int t = 2; t < G.size(); t++) {
        while(crossProductAntiOrder(G[antiOrder.beforeTop()], G[antiOrder.top()], G[t]) <= 0 && !antiOrder.empty()) {
            antiOrder.pop();
        }
        antiOrder.push(t);
    }
    aIndex = -1;
    while(!antiOrder.empty()) {
        if(aIndex == -1) {
            aIndex = antiOrder.top();
            antiOrder.pop();
        } else {
            aIndex = bIndex;
        }
        bIndex = antiOrder.top();
        antiOrder.pop();
        totLen += lenCalc(G[aIndex], G[bIndex]);
    }
    printf("%.2f\n", totLen);
    return 0;
}