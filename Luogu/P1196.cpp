// https://blog.csdn.net/janis_z/article/details/52688831

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXI 30003

int T;

struct UFSET {
    int fa[MAXI], dis[MAXI], last[MAXI];
    int find(int n) {
        if(fa[n] == n) return n;
        int last = fa[n];
        fa[n] = find(fa[n]);
        dis[n] += dis[last];
        return fa[n];
        /*
        if(fa[target] == target) return target;
        while(fa[fa[target]] != fa[target]) {
            fa[target] = fa[fa[target]];
            dis[target] += dis[fa[target]];
        }
        return fa[target];
        */
    }
    // dis[i] represents the distance from i to fa[i]
    inline void merge(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) {
            fa[a] = b;
            dis[a] += last[b];
            last[b] += last[a];
        }
    }
    inline int query(int a, int b) {
        int x = find(a), y = find(b);
        if(x != y) {
            return -1;
        } else {
            return abs(dis[a] - dis[b]) - 1;
        }
    }
    inline void initialize() {
        for(int t = 1; t < MAXI; t++) {
            fa[t] = t;
            last[t] = 1;
        }
    }
} U;

char op; int i, j;

int main() {
    ios::sync_with_stdio(false);
    U.initialize();
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> op >> i >> j;
        switch(op) {
            case 'M':
                U.merge(i, j);
                break;
            case 'C':
                cout << U.query(i, j) << endl;
                break;
        }
    }
    return 0;
}