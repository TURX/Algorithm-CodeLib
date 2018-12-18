// http://noi.openjudge.cn/ch0202/6261/
// https://blog.csdn.net/a7055117a/article/details/48348821

#include <iostream>
using namespace std;

int N;
string a, b, c;
#define MAXN 100001

struct StackBox {
    int stack[MAXN];
    int pointer = 0;
    inline void push(const char& val) {
        stack[pointer++] = val;
    }
    inline void pop() {
        pointer--;
    }
    inline int top() {
        return stack[pointer];
    }
    inline bool empty() {
        return !pointer;
    }
} S[3];

void Hanoi(int n, string x, string y, string z) {
    if(n) {
        Hanoi(n - 1, x, z, y);
        cout << x << "->" << n << "->" << y << endl;
        Hanoi(n - 1, z, y, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> a >> b >> c;
    Hanoi(N, a, b, c);
    return 0;
}