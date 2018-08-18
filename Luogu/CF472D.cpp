// https://www.cnblogs.com/zhber/p/4035894.html

#include <iostream>
using namespace std;

int N, M[401][401];

struct ufset{
    int ufset[5001];
    inline void init(const int& n) {
        for(int t = 1; t <= n; t++)
            ufset[t] = t;
    }
    inline int find(int x) {
        return ufset[x] == x ? x : (ufset[x] = find(ufset[x]));
    }
} S;

inline bool directlyAbolish() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j && M[i][i]) return false;
            if(i != j && !M[i][j]) return false;
            if(M[i][j] != M[i][j]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> M[i][j];
        }
    }
    if(!directlyAbolish()) {
        cout << "NO" << endl;
        return 0;
    }
    return 0;
}