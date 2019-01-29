#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 1001

int N, M, E, u, v, maximumMatch;
vector<int> G[MAXN];
int Satis[MAXN], Accord[MAXN]; // Satis是人，Accord是物

inline bool findSatis(const int& id);
inline int converseModify(const int& id);
inline bool converse(const int& unmatched, const int& matched);

int main() {
    scanf("%d%d%d", &N, &M, &E);
    for(int t = 0; t < E; t++) {
        scanf("%d%d", &u, &v);
        if(v > M || u > N) continue;
        G[u].push_back(v);
    }
    for(int i = 1; i <= N; i++) {
        if(!findSatis(i)) {
            for(int j = 1; j < i; j++) {
                if(converse(i, j)) break;
            }
        }
    }
    printf("%d\n", maximumMatch);
    return 0;
}

inline bool findSatis(const int& id) {
    vector<int>& waitingList = G[id];
    for(int t = 0; t < waitingList.size(); t++) {
        if(!Accord[waitingList[t]]) {
            Satis[id] = t;
            Accord[waitingList[t]] = id;
            maximumMatch++;
            return true;
        }
    }
    return false;
}

inline int converseModify(const int& id) { // Matched
    vector<int>& waitingList = G[id];
    int ans = -1;
    for(int t = Satis[id] + 1; t < waitingList.size(); t++) {
        if(!Accord[waitingList[t]]) {
            Satis[id] = waitingList[t];
            return t;
        }
    }
    return ans;
}

inline void converseBack(const int& id) {
    vector<int>& waitingList = G[id];
    for(int t = 0; t < min((int)waitingList.size(), Satis[id]); t++) {
        if(!Accord[waitingList[t]]) {
            Satis[id] = waitingList[t];
        }
    }
}

inline bool converse(const int& unmatched, const int& matched) {
    vector<int>& waitingList = G[unmatched];
    for(int t = 0; t < waitingList.size(); t++) {
        if(converseModify(matched) == -1) continue; // Conversation failed
        if(findSatis(unmatched)) return true;
    }
    converseBack(matched);
    return false;
}