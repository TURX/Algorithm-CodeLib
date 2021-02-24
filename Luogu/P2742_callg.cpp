#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

#define rep(i, N, m) for(int i = N; i <= m; i++)
const int MAXN = 10001;

using namespace std;

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
        if(!siz) return -1;
        return data[siz];
    }
    bool empty() {
        return !siz;
    }
    int size() {
        return siz;
    }
    int beforeTop() {
        if(!(siz - 1)) return -1;
        return data[siz - 1];
    }
} stack;

vector<Point> G;

inline bool inOrderCmp(const Point& lhs, const Point& rhs) {
    return (lhs.x == rhs.x) ? (lhs.y < rhs.y) : (lhs.x < rhs.x);
}

inline bool antiOrderCmp(const Point& lhs, const Point& rhs) {
    return !inOrderCmp(lhs, rhs);
}

int N, cur = 2;
double totLen, x, y;

inline bool judge(int now) {
    // x1 * y2 - x2 * y1
    return ((G[stack.top()].x - G[stack.beforeTop()].x) * (G[now].y - G[stack.top()].y) - (G[now].x - G[stack.top()].x) * (G[stack.top()].y - G[stack.beforeTop()].y)) <= 0;
}

inline double squareCalc(const double& num) {
    return num * num;
}

inline double dis() {
    return sqrt(squareCalc(G[stack.top()].x - G[stack.beforeTop()].x) + squareCalc(G[stack.top()].y - G[stack.beforeTop()].y));
}

int main()
{
    scanf("%d", &N);
    while(N--) {
        scanf("%lf%lf", &x, &y);
        G.push_back({x, y});
    }
    
    //下凸壳
    sort(G.begin(), G.end(), inOrderCmp);
    stack.push(0), stack.push(1);
    for(int t = 2; t < N; t++) {
        while((stack.siz > 1) && judge(t)) stack.pop();
        stack.push(t);
    }

    while(stack.siz > 2) {
        totLen += dis();
        stack.pop();
    }

    stack.siz = 0;
    
    //上凸壳
    sort(G.begin(), G.end(), antiOrderCmp);
    stack.push(0), stack.push(1);
    for(int t = 2; t < N; t++) {
        while((stack.siz > 1) && judge(t)) stack.pop();
        stack.push(t);
    }

    while(stack.siz > 2) {
        totLen += dis();
        stack.pop();
    }
        
    printf("%1.2f\n", totLen);
    return 0;
}