#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 2000001;
int N, M, O, X, Y, D[MAXN];

inline int lowbit(const int& k) {
    return k & -k;
}

inline void add(int x, const int& k) {
    while(x <= N) {
        D[x] += k;
        x += lowbit(x);
    }
}

inline int sum(int x) {
    int ans = 0;
    while(x) {
        ans += D[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int t = 1; t <= N; t++) {
        scanf("%d", &X);
        add(t, X);
    }
    while(M--) {
        scanf("%d%d%d", &O, &X, &Y);
        switch(O) {
            case 1:
                add(X, Y);
                break;
            case 2:
                if(Y < X) swap(X, Y);
                cout << sum(Y) - sum(X - 1) << endl;
                break;
        }
    }
    return 0;
}