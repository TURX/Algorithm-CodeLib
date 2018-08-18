#include <iostream>
#include <algorithm>

const int MaxN = 300 + 10;
const int INF = 0x3f3f3f3f;

int N, W[MaxN], cnt = 1, P[MaxN][MaxN];

struct Edge {
    int u, v, weight;
} edge[MaxN * MaxN + MaxN];

struct UnionFindSet {
    int father[MaxN];
    inline void Init(const int &__size) {
        for (int i = 1; i <= __size; ++i) father[i] = i;
    }
    inline int Find(int o) {
        return (father[o] == o) ? o : father[o] = Find(father[o]);
    }
} ufs;

inline bool cmp(const Edge &__a, const Edge &__b) {
    return __a.weight < __b.weight;
}

int Krushal() {
    int ans = 0, x = 0;
    std::sort(edge + 1, edge + cnt + 1, cmp);
    ufs.Init(N);
    for (int i = 1; i <= cnt; ++i) {
        int xx = ufs.Find(edge[i].u), yy = ufs.Find(edge[i].v);
        if (xx != yy) {
            ufs.father[xx] = yy;
            ++x;
            ans += edge[i].weight;
        }
        if (x == N) return ans;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        std::cin >> W[i];
        edge[cnt++].u = 0;
        edge[cnt].v = i;
        edge[cnt].weight = W[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            std::cin >> P[i][j];
            if (i > j) {
                cnt++;
                edge[cnt].u = i;
                edge[cnt].v = j;
                edge[cnt].weight = P[i][j];
            }
        }
    }
    int ans = Krushal();
    std::cout << ans;
    return 0;
}